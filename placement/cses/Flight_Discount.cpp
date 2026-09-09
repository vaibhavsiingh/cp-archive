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

void djikstra(vector<vector<pll>>& adj, vector<ll>& dist, ll nd){
    dist[nd]  = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, nd});

    while(!pq.empty()){
        auto [d, nd] = pq.top();
       // o2("nd", nd);
        pq.pop();

        if(dist[nd] < d) continue;

        for(auto [nxt,c]: adj[nd]){
            if(dist[nxt] > dist[nd]+c){
                dist[nxt] = dist[nd]+c;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

void sol(){
    ll n,m;
    cin >> n >> m;
    
    vector<vll> edges(m, vll(3));
    vector<vector<pll>> adj(n+1), radj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        edges[i] = {x,y,z};
        adj[x].pb({y,z});
        radj[y].pb({x,z});        
    }

    vector<ll> dist(n+1, INF), rdist(n+1, INF);

    djikstra(adj, dist, 1);
    djikstra(radj, rdist, n);

    // oArray(dist, n+1);
    // o1("");
    // oArray(rdist, n+1);

    ll mn = dist[n];
    for(auto e: edges){
        ll a = e[0], b = e[1], c = e[2];

        mn = min(mn, dist[a] + c/2 + rdist[b]);
    }
    o1(mn);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}