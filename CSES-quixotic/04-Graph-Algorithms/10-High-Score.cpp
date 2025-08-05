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

const ll MOD = 1000000007;

ll n,m;
vector<vector<pll>> adj, radj;
vll visited,rvisited;
vll dist;
vector<vll> edges;

void dfs(ll nd){
    visited[nd]=1;
    for(auto [nxt,wt]:adj[nd]){
        if(visited[nxt]) continue;
        dfs(nxt);
    }
}

void rdfs(ll nd){
    rvisited[nd]=1;
    for(auto [nxt,wt]:radj[nd]){
        if(rvisited[nxt]) continue;
        rdfs(nxt);
    }
}

void sol(){
    i2(n,m);
    adj.resize(n+1);
    radj.resize(n+1);
    visited.resize(n+1);
    rvisited.resize(n+1);
    dist = vll(n+1,1e18);
    edges.resize(m);

    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,-z});
        radj[y].pb({x,-z});
        edges[i] = {x,y,-z};
    }
    dfs(1);
    rdfs(n);

    dist[1] = 0;
    bool improvement=true;
    for(ll i=0; (i<n && improvement); i++){
        improvement = false;
        for(auto e:edges){
            ll x=e[0],y=e[1],wt=e[2];
            if(dist[x]!=1e18 && dist[y]>dist[x]+wt){
                dist[y] = dist[x]+wt;
                improvement=true;
                if(i==n-1 && visited[y] && rvisited[y]){
                    //reach;
                    o1(-1);
                    return;
                }
            }
        }
    }
    o1(-dist[n]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}