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
vector<vector<pll>> adj,radj;
vll dist;
vll rdist;
vector<vll> edges;
 
void djikstra(ll src){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,src});
    dist[src] = 0;
    while(!pq.empty()){
        ll nd = pq.top().ss, d = pq.top().ff;
        pq.pop();

        if(d>dist[nd]) continue;
        for(auto [nxt,wt]:adj[nd]){
            if(dist[nxt]>dist[nd]+wt){
                dist[nxt]=dist[nd]+wt;
                pq.push({dist[nxt],nxt});
            }
        }
    }
}
 
void rdjikstra(ll src){
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,src});
    rdist[src] = 0;
    while(!pq.empty()){
        ll nd = pq.top().ss, d = pq.top().ff;
        pq.pop();
        if(d>rdist[nd]) continue;
        for(auto [nxt,wt]:radj[nd]){
            if(rdist[nxt]>rdist[nd]+wt){
                rdist[nxt]=rdist[nd]+wt;
                pq.push({rdist[nxt],nxt});
            }
        }
    }
}
 
void sol(){
    i2(n,m);
    adj.resize(n+1);
    radj.resize(n+1);
    dist.resize(n+1,1e18);
    rdist.resize(n+1,1e18);
    edges.resize(m,vll(3));
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
        radj[y].pb({x,z});
        edges[i] = {x,y,z};
    }
    djikstra(1);
    rdjikstra(n);
    ll ans = 1e18;
    for(auto e:edges) {
        ll x = e[0], y=e[1], wt = e[2];
        ans= min(ans, dist[x]+rdist[y]+wt/2);
    }
   // oArray(dist,n+1);
   // oArray(rdist,n+1); 
    o1(ans);
    
}
 
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
