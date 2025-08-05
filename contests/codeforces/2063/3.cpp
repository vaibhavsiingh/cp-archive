#include <bits/stdc++.h>
using namespace std;

int maxComponents(int n, vector<vector<int>>& edges) {
    // Build adjacency list and degrees
    vector<vector<int>> adj(n);
    vector<int> degree(n);
    
    for (const auto& edge : edges) {
        int u = edge[0] - 1, v = edge[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    // Store vertices by degree
    priority_queue<pair<int,int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({degree[i], i});
    }
    
    // Get vertex with max degree
    int v1 = pq.top().second;
    int d1 = pq.top().first;
    pq.pop();
    
    // Find highest degree vertex not adjacent to v1
    set<int> neighbors(adj[v1].begin(), adj[v1].end());
    while (!pq.empty()) {
        auto [d2, v2] = pq.top();
        pq.pop();
        
        if (neighbors.count(v2)) continue;
        
        // v1 removal creates d1 components
        // v2 removal creates d2 additional components
        return d1 + d2;
    }
    
    return 0;
}

void sol() {
    int n, m;
    cin >> n;
    m= n-1;
    vector<vector<int>> edges(m, vector<int>(2));
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    cout << maxComponents(n, edges) << endl;
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) sol();
}