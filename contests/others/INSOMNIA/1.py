def solve():
    import sys
    data = sys.stdin.read().split()
    if not data:
        return
    x = int(data[0])
    y = int(data[1])
    
    # If y > x, then no number v in [0,x] can have y as a submask.
    if y > x:
        print(-1)
        return

    # Start with candidate v equal to y.
    candidate = y
    # Try to add as many additional bits (starting from the lowest)
    # while ensuring that candidate remains <= x.
    # We consider up to 64 bits.
    for i in range(64):
        if candidate | (1 << i) <= x:
            candidate |= (1 << i)
    
    # Count the number of bits in candidate (popcount).
    r = bin(candidate).count("1")
    
    # Now determine the maximum possible size m of the set S.
    if y == 0:
        # When y is 0, note that U_v (the set of submasks of candidate)
        # has XOR 0 only if popcount(candidate) >= 2.
        if r <= 1:
            print(1)
        else:
            print(1 << r)  # This is 2^r.
    else:
        # When y > 0, we need y ⊆ candidate.
        # For r = 1, the only possibility is candidate = y and U_v = {0, y}.
        # For r >= 2, one may choose S = U_v \ {y}, which gives 2^r - 1 elements.
        if r == 1:
            print(2)
        else:
            print((1 << r) - 1)

if __name__ == '__main__':
    solve()
