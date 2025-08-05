#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

void dijkstra(vector<vector<pll>>& adj, vll& dist) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while (!pq.empty()) {
        ll d = pq.top().first, node = pq.top().second;
        pq.pop();
        
        if (d > dist[node]) continue;
        
        for (auto [nxt, w] : adj[node]) {
            if (dist[nxt] > d + w) {
                dist[nxt] = d + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

void sol() {
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    vll distance(n + 1, 1e18);  

    for (ll i = 0; i < m; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    
    dijkstra(adj, distance);
    
    for (ll i = 1; i <= n; i++) {
            cout << distance[i] << " ";
        
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
