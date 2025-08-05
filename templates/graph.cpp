

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define sz size
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;

const ll MOD = 1000000007;

void dfs(vector<vll>& adj, vll& visited, ll start){
    visited[start] = 1;
    for(auto c:adj[start]){
        if(visited[c]) continue;
        dfs(adj,visited,c);
    }
}

// keep visited = vll(n+1,-1);
void bfs(vector<vll>& adj, vll& visited, ll start){
    queue<ll> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        ll a=q.front();
        q.pop();
        for(ll child:adj[a]){
            if(visited[child]>=0) continue;
            visited[child] = visited[a]+1;
            q.push(child);
        }
    }
    return;
}

vector<int> toposort(int n, const vector<vector<int>>& adj) {
    vector<int> in_deg(n, 0);
    for (int u = 0; u < n; ++u)
        for (int v : adj[u])
            in_deg[v]++;

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (in_deg[i] == 0)
            q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--in_deg[v] == 0)
                q.push(v);
        }
    }

    // Check for cycle
    if (order.size() != n) return {}; // return empty if cycle detected
    return order;
}

void Dijkstra(vector<vector<pll>> adj, vll& distance, ll start ){
    vll processed(distance.size(),0);
    distance[start] = 0;
    priority_queue<pair<ll,ll>> q;
    q.push({0,start});
    while(!q.empty()){
        ll node = q.top().ss;q.pop();
        if(processed[node]==1) continue;
        processed[node] = 1;
       for(pll child:adj[node]){
            ll b = child.ff, w=child.ss;
            if(distance[b]>distance[node]+w){
                distance[b]=distance[node]+w;
                q.push({-distance[b],b});
            }
        }
    }

}




void dfsForTopSort(int s, vll& visited, vector<vll>& adj, stack<ll>& stk) {
    if (visited[s]) return;
    visited[s] = true;
    // process node s
    vll ans;
    for (auto u: adj[s]) {
        dfsForTopSort(u, visited, adj, stk);
    }
    stk.push(s);
}

vll topoSort(vector<vll> adj, vll& processed){
    ll n=adj.size()-1;
    stack<ll> stk;
    for(ll node=1; node<=n; node++ ){
        if(processed[node]) continue;
        dfsForTopSort(node,processed,adj,stk);
    }
    vll ans;

    while(!stk.empty()){
        ans.pb(stk.top());
        stk.pop();
    }
    return ans;
}

void sol(){
    ll n,m;
    i2(n,m);
    vector<vll> adj(n+1);
    vll visited(n+1,0);
    for(ll i = 0; i < m; i++) {
        ll a,b;
        i2(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }

}

// weighted graph input with 
void sol(){
    ll n,m;
    i2(n,m);
    vector<vector<pll>> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll a,b,d;
        i2(a,b);
        cin >> d;
        adj[a].pb({b,d});
        // directed graph this
    }
    
    vll distance(n+1,1e18);
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
