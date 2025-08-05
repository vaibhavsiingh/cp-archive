import sys
import threading
from collections import deque

def solve():
    input = sys.stdin.readline
    T_line = input().strip()
    if not T_line:
        return
    T = int(T_line)
    for _ in range(T):
        line = input().strip()
        while line == "":
            line = input().strip()
        n = int(line)
        adj = [[] for _ in range(n+1)]
        for _ in range(n-1):
            u,v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)

        # Step 1: find v of degree 2 with a leaf neighbor u
        v = -1; u = -1; w = -1
        for node in range(1, n+1):
            if len(adj[node]) == 2:
                # check if one neighbor is leaf
                a,b = adj[node]
                if len(adj[a]) == 1:
                    v = node; u = a; w = b
                    break
                if len(adj[b]) == 1:
                    v = node; u = b; w = a
                    break
        if v == -1:
            print("NO")
            continue

        # We'll collect orientations in a list of (from, to)
        oriented = []
        used = set()  # track oriented edges as unordered frozenset

        # Step 2: orient u->v and v->w
        oriented.append((u, v))
        used.add(frozenset((u,v)))
        oriented.append((v, w))
        used.add(frozenset((v,w)))

        # Step 3: at w, orient all other edges x-w as x->w
        for x in adj[w]:
            if x == v: continue
            oriented.append((x, w))
            used.add(frozenset((x,w)))
            # Step 4: BFS in subtree rooted at x, avoid revisiting w
            dq = deque()
            dq.append((x, 0))  # depth 0 at x
            parent = {x: w}
            while dq:
                node, depth = dq.popleft()
                for nei in adj[node]:
                    if nei == parent[node]:
                        continue
                    # edge between node (parent in BFS) and nei
                    d = depth + 1
                    if d % 2 == 1:
                        # odd depth: orient node -> nei
                        oriented.append((node, nei))
                    else:
                        # even depth: orient nei -> node
                        oriented.append((nei, node))
                    used.add(frozenset((node,nei)))
                    parent[nei] = node
                    dq.append((nei, d))

        # Verify all edges covered (just in case)
        if len(oriented) != n-1:
            # fail-safe (shouldn't happen if logic is correct)
            print("NO")
            continue

        print("YES")
        for a,b in oriented:
            print(a, b)

if __name__ == "__main__":
    threading.Thread(target=solve).start()
