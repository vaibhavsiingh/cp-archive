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

void sol(){
    ll n,m;
    cin >> n >> m;
    
    vector<vector<pll>> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vll s(n);
    iArray(s,n);
    s.insert(s.begin(), 0);
    
    using distnode = array<ll, 3>;
    priority_queue<distnode, vector<distnode>, greater<distnode>> pq;
    
    pq.push(distnode{0, 1, s[1]});
    vector<vll> dist(n+1, vll(1001, INF));
    dist[1][s[1]] = 0;
    while(!pq.empty()){
        auto x = pq.top();
        ll pqd = x[0], nd = x[1], sl = x[2];
      //  o2(nd, sl);
        pq.pop();
        if(pqd > dist[nd][sl]) continue;

        ll slm = min(sl, s[nd]);
        for(auto [nxt, d]: adj[nd]){
            if(dist[nxt][slm] > pqd + slm*d){
                dist[nxt][slm] = pqd + slm*d;
                pq.push(distnode{dist[nxt][slm], nxt, slm});
            }
        }
    }

    ll mn = INF;
    for(ll i=0; i<=1000; i++){
        mn = min(mn, dist[n][i]);
    }
    o1(mn);

 
    

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}