    #include <bits/stdc++.h>
    using namespace std;

    typedef int64_t ll;
    typedef vector<ll> vll;
    typedef pair<ll, ll> pll;
    typedef complex<ll> P;

    #define X real()
    #define Y imag()
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
    #define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
    #define rep(i, a, b) for (int i = (a); i < (b); i++)
    #define rep0(i, n) for (int i = 0; i < (n); i++)
    #define all(x) x.begin(), x.end()
    #define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

    const ll MOD = 1000000007;
    const ll INF = 1e18;

    vector<bool> visited; // keeps track of which vertices are already visited

    // runs depth first search starting at vertex v.
    // each visited vertex is appended to the output vector when dfs leaves it.
    void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
        visited[v] = true;
        for (auto u : adj[v])
            if (!visited[u])
                dfs(u, adj, output);
        output.push_back(v);
    }

    // input: adj -- adjacency list of G
    // output: components -- the strongy connected components in G
    // output: adj_cond -- adjacency list of G^SCC (by root vertices)
    void strongly_connected_components(vector<vector<int>> const& adj,
                                    vector<vector<int>> &components,
                                    vector<vector<int>> &adj_cond) {
        int n = adj.size();
        components.clear(), adj_cond.clear();

        vector<int> order; // will be a sorted list of G's vertices by exit time

        visited.assign(n, false);

        // first series of depth first searches
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(i, adj, order);

        // create adjacency list of G^T
        vector<vector<int>> adj_rev(n);
        for (int v = 0; v < n; v++)
            for (int u : adj[v])
                adj_rev[u].push_back(v);

        visited.assign(n, false);
        reverse(order.begin(), order.end());

        vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

        // second series of depth first searches
        for (auto v : order)
            if (!visited[v]) {
                std::vector<int> component;
                dfs(v, adj_rev, component);
                components.push_back(component);
                int root = *min_element(begin(component), end(component));
                for (auto u : component)
                    roots[u] = root;
            }

        // add edges to condensation graph
        adj_cond.assign(n, {});
        for (int v = 0; v < n; v++)
            for (auto u : adj[v])
                if (roots[v] != roots[u])
                    adj_cond[roots[v]].push_back(roots[u]);
    }

    void sol(){
        ll n,m;        
        cin >> n >> m;
        vector<vector<int>> bigadj(n);
        for(ll i = 0; i < m; i++) {
            int x,y;
            cin >> x >> y;
            x--;
            y--;
            bigadj[x].pb(y);
        }
        vector<vector<int>> components, adj;
        strongly_connected_components(bigadj, components, adj);

        vll node2com(n);
        for(int i=0; i<components.size(); i++){
            vector<int> v = components[i];
            for(auto nd: v){
                node2com[nd] = i;
            }
        }        
        
        
        vector<vector<int>> rev_adj(components.size());
        for(int i=0; i<adj.size(); i++){
            for(auto y: adj[i]){                
                rev_adj[node2com[y]].pb(node2com[i]);
            }
        }

        ll q;
        cin >> q;
        vll black(components.size());
        while(q--){
            ll qt, nd;
            i2(qt,nd);
            nd--;
            if(qt==1){
                ll comp2color = node2com[nd];
                if(black[comp2color]) continue;
                queue<int> q;
                q.push(comp2color);
                                
                black[comp2color] = 1;
                while(!q.empty()){
                    ll ndd = q.front();
                    q.pop();                    
                    for(auto x: rev_adj[ndd]){
                        if(black[x])continue;                        
                        black[x] = 1;
                        q.push(x);
                    }
                }
            }
            else{
                if(black[node2com[nd]]){
                    o1("Yes");                
                }
                else o1("No");
            }
        }


    }

    int main(){
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        sol();
        return 0;
    }