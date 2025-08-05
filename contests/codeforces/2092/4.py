def balance_drink(s):
    # convert string to list for easy insertion
    s = list(s)
    n = len(s)
    
    # counts of each substance
    cnt = {'L': s.count('L'), 'I': s.count('I'), 'T': s.count('T')}
    
    # try to pick a valid k
    valid_k = None
    for k in range(0, 2*n + 1):
        if (n + k) % 3 != 0:
            continue
        target = (n + k) // 3
        if cnt['L'] <= target and cnt['I'] <= target and cnt['T'] <= target:
            valid_k = k
            break
    
    if valid_k is None:
        return None  # impossible
    
    target = (n + valid_k) // 3
    need = {
        'L': target - cnt['L'],
        'I': target - cnt['I'],
        'T': target - cnt['T']
    }
    
    # A helper to determine the forced insertion letter between a and b.
    def forced_letter(a, b):
        for ch in "LIT":
            if ch != a and ch != b:
                return ch

    ops = []  # record operations as (index, inserted_letter)
    # We'll try up to 2n operations (which is our limit)
    ops_count = 0
    while any(need[ch] > 0 for ch in "LIT"):
        made_progress = False
        i = 0
        while i < len(s) - 1 and ops_count < 2*n:
            if s[i] != s[i+1]:
                letter_to_insert = forced_letter(s[i], s[i+1])
                if need[letter_to_insert] > 0:
                    # record the operation: we insert after index i (using 0-indexing)
                    ops.append((i, letter_to_insert))
                    s.insert(i+1, letter_to_insert)
                    need[letter_to_insert] -= 1
                    ops_count += 1
                    made_progress = True
                    # after insertion, check from i-1 if possible (to catch new pairs)
                    i = max(i-1, 0)
                    continue  # re-check at new position
            i += 1
        if not made_progress:
            # no available move to insert a needed letter
            break

    if any(need[ch] > 0 for ch in "LIT"):
        return None  # impossible to balance
    return "".join(s), ops

# Example usage:
input_str = "LITT"
result = balance_drink(input_str)
if result is None:
    print("Impossible")
else:
    final_string, operations = result
    print("Final balanced string:", final_string)
    print("Operations (0-indexed positions):")
    for idx, letter in operations:
        print(f"Insert {letter} after position {idx}")
