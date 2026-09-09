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

void sol(){
    ll n,m;
    cin >> n >> m;

    vector<vector<pll>> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >>z;
        adj[x].push_back({y,z});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> dist(n+1, INF);
    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        auto [d, nd] = pq.top();
        pq.pop();

        if(dist[nd]<d) continue;

        for(auto [nxt, c]: adj[nd]){
            if(d+c < dist[nxt]){
                dist[nxt] = d+c;
                pq.push({dist[nxt], nxt});                
            }
        }
    }

    for(ll i = 0; i < n; i++) {
        cout << dist[i+1] << ' ';
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}