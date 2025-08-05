import sys
import math
from collections import Counter

def solve():
    input_data = sys.stdin.read().strip().split()
    if not input_data:
        return
    # First integer is N, then N numbers
    it = iter(input_data)
    N = int(next(it))
    A = [int(next(it)) for _ in range(N)]
    
    maxA = max(A)
    # Count occurrences for each number up to maxA.
    cnt = [0]*(maxA+1)
    for a in A:
        cnt[a] += 1

    answer = 0
    # For each candidate g from 1 to maxA:
    for g in range(1, maxA+1):
        total = 0
        current_gcd = 0
        # iterate over multiples of g
        for m in range(g, maxA+1, g):
            if cnt[m]:
                total += cnt[m]
                # For gcd, note that m//g is the "factor" left after factoring g
                if current_gcd == 0:
                    current_gcd = m // g
                else:
                    current_gcd = math.gcd(current_gcd, m // g)
                # early break if gcd becomes 1
                if current_gcd == 1 and total == N:
                    # cannot improve gcd further
                    pass
        if total > 0 and current_gcd == 1:
            candidate = total + g
            if candidate > answer:
                answer = candidate

    print(answer)

if __name__ == '__main__':
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        solve()
