def sieve(n):
    """Return a list is_prime where is_prime[i] is True if i is a prime, for 0 <= i <= n."""
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    p = 2
    while p * p <= n:
        if is_prime[p]:
            for i in range(p * p, n + 1, p):
                is_prime[i] = False
        p += 1
    return is_prime

def build_graph(evens, odds, is_prime):
    """
    Build a bipartite graph where each even number is connected to odd numbers if their sum is prime.
    The graph is represented as a dictionary: graph[u] = list of neighbors in odds.
    """
    graph = {}
    for e in evens:
        neighbors = []
        for o in odds:
            if is_prime[e + o]:
                neighbors.append(o)
        graph[e] = neighbors
    return graph

def hopcroft_karp(graph, evens, odds):
    """
    Implementation of the Hopcroft-Karp algorithm for bipartite matching.
    graph: dictionary mapping each even node to list of odd nodes.
    evens: list of nodes in the left partition.
    odds: list of nodes in the right partition.
    Returns: matching dictionary and size of matching.
    """
    from collections import deque

    # Pair dictionaries. pair_u[u] is the partner of u (or None if unmatched).
    pair_u = {u: None for u in evens}
    pair_v = {v: None for v in odds}
    # Distance dictionary for BFS
    dist = {}

    def bfs():
        queue = deque()
        # Initialize distances for free vertices in evens
        for u in evens:
            if pair_u[u] is None:
                dist[u] = 0
                queue.append(u)
            else:
                dist[u] = float('inf')
        dist[None] = float('inf')  # Sentinel

        while queue:
            u = queue.popleft()
            if dist[u] < dist[None]:
                for v in graph[u]:
                    if dist[pair_v[v]] == float('inf'):
                        dist[pair_v[v]] = dist[u] + 1
                        queue.append(pair_v[v])
        return dist[None] != float('inf')

    def dfs(u):
        if u is not None:
            for v in graph[u]:
                if dist[pair_v[v]] == dist[u] + 1:
                    if dfs(pair_v[v]):
                        pair_v[v] = u
                        pair_u[u] = v
                        return True
            dist[u] = float('inf')
            return False
        return True

    matching = 0
    while bfs():
        for u in evens:
            if pair_u[u] is None:
                if dfs(u):
                    matching += 1

    return pair_u, matching

# Example usage:
if __name__ == "__main__":
    # Sample sets of even and odd numbers. Adjust these lists as needed.
    evens = [2, 4, 6, 8]
    odds  = [1, 3, 5, 7]
    
    # Determine maximum possible sum to set limit for sieve.
    max_sum = max(evens) + max(odds)
    is_prime = sieve(max_sum)
    
    # Build bipartite graph.
    graph = build_graph(evens, odds, is_prime)
    
    # Run Hopcroft-Karp algorithm to find maximum matching.
    matching, size = hopcroft_karp(graph, evens, odds)
    
    print("Matching size:", size)
    print("Matching pairs:")
    for u in evens:
        if matching[u] is not None:
            print(f"{u} -> {matching[u]}")
 