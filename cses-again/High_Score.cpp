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
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void dfs(vector<vll>& adj, vll& vis, int nd){
    vis[nd] = 1;
    
    for(ll nxt: adj[nd]){
        if(!vis[nxt]){
            dfs(adj, vis, nxt);
        }
    }
}

void sol(){
    ll n,m;
    cin >> n >> m;
    
    vector<vll> edges(m, vll(3));
    vector<vll> adj(n+1), radj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        edges[i] = {x,y,-z};
        adj[x].pb(y);
        radj[y].pb(x);        
    }

    vll dist(n+1, INF);
    dist[1] = 0;
    vll vis(n+1,0);
    dfs(adj, vis, 1);

    vll rvis(n+1,0);
    dfs(radj, rvis, n);

    for(ll i = 1; i <= n; i++) {
        for(auto e: edges){
            ll a = e[0], b = e[1], c = e[2];
            if(dist[a]==INF) continue;
            if(dist[a] + c < dist[b]){
                if(i==n){
                    if(vis[a] && rvis[b]){
                        o1(-1);
                        return;
                    }
                }
                dist[b] = dist[a]+c;
            }
        }
    }
    

    if(dist[n] <= -INF){
        o1(-1);
    }
    o1(-dist[n]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}