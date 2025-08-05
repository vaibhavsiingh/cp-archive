def solve():
    import sys,sys
    data = sys.stdin.buffer.read().split()
    if not data: 
        return
    t = int(data[0])
    index = 1
    out_lines = []
    
    MOD = 998244353
    
    maxN = 210000
    fact = [1]*(maxN)
    invfact = [1]*(maxN)
    for i in range(1, maxN):
        fact[i] = fact[i-1]*i % MOD
    invfact[maxN-1] = pow(fact[maxN-1], MOD-2, MOD)
    for i in range(maxN-2, -1, -1):
        invfact[i] = invfact[i+1]*(i+1) % MOD
    def nCr(n, r):
        if r < 0 or r > n:
            return 0
        return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD

    
    mod1 = 1000000007
    mod2 = 1000000009
    base1 = 100007
    base2 = 100009
    offset = 100 
    
   
    for _ in range(t):
        if index >= len(data):
            break
        try:
            n = int(data[index])
        except:
            break
        index += 1
        m = int(data[index])
        index += 1
        n = int(n)
        m = int(m)
        arr = [int(x) for x in data[index:index+n]]
        index += n
        
        if m == 1:
            out_lines.append("0 " + str(n % MOD))
            continue
        
       
        arr.sort()
        
        
        S = [0]*(n+1)
        S2 = [0]*(n+1)
        for i in range(n):
            S[i+1] = S[i] + arr[i]
            S2[i+1] = S2[i] + (i+1)*arr[i]
        
        bestF = None
        best_hashes = {}  
        
        
        H1 = [0]*n
        H2 = [0]*n
        power1 = [1]*(n+1)
        power2 = [1]*(n+1)
        H1[0] = (arr[0] + offset) % mod1
        H2[0] = (arr[0] + offset) % mod2
        for i in range(1, n):
            H1[i] = (H1[i-1]*base1 + (arr[i] + offset)) % mod1
            H2[i] = (H2[i-1]*base2 + (arr[i] + offset)) % mod2
        for i in range(1, n+1):
            power1[i] = (power1[i-1]*base1) % mod1
            power2[i] = (power2[i-1]*base2) % mod2

        
        dup = [0]*(n-1)
        for i in range(n-1):
            dup[i] = 1 if arr[i] == arr[i+1] else 0
        pd = [0]*(n+1)
        for i in range(1, n+1):
            pd[i] = pd[i-1] + (dup[i-1] if i-1 < len(dup) else 0)
        
      
        for l in range(0, n - m + 1):
            r = l + m - 1
            seg_S2 = S2[r+1] - S2[l]
            seg_S = S[r+1] - S[l]
            curF = 4 * seg_S2 - 2 * ((l+1) + (r+1)) * seg_S
            if bestF is None or curF < bestF:
                bestF = curF
                best_hashes.clear()
            if curF == bestF:
                if l == 0:
                    h1 = H1[r]
                    h2 = H2[r]
                else:
                    h1 = (H1[r] - H1[l-1] * power1[r - l + 1]) % mod1
                    h2 = (H2[r] - H2[l-1] * power2[r - l + 1]) % mod2
                key = (h1, h2, r - l + 1)  # include the segment length for safety.
                if key not in best_hashes:
                    best_hashes[key] = l

        groups = []
        group_id = [0]*n
        gstart = 0
        gid = 0
        for i in range(n):
            if i == n-1 or arr[i] != arr[i+1]:
                groups.append((gstart, i, arr[gstart], i - gstart + 1))
                for j in range(gstart, i+1):
                    group_id[j] = gid
                gid += 1
                gstart = i+1

        total_count = 0
        for key, L in best_hashes.items():
            R = L + m - 1
            if pd[R] - pd[L] == 0:
                ways = 1
            else:
                gl = group_id[L]
                gr = group_id[R]
                if gl == gr:
                    tot = groups[gl][3]
                    rcount = R - L + 1
                    ways = nCr(tot, rcount)
                else:
                    tot_left = groups[gl][3]
                    left_count = groups[gl][1] - L + 1
                    ways_left = nCr(tot_left, left_count)
                    tot_right = groups[gr][3]
                    right_count = R - groups[gr][0] + 1
                    ways_right = nCr(tot_right, right_count)
                    ways = ways_left * ways_right % MOD
            total_count = (total_count + ways) % MOD
        
        out_lines.append(f"{bestF} {total_count}")
    sys.stdout.write("\n".join(out_lines))
    
if __name__ == '__main__':
    solve()
