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
    vector<vll> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);   
        adj[y].pb(x);        
    }

    vll dp_prev(n + 1, INF), dp_curr(n + 1, INF);
    dp_prev[1] = 0;
    ll found = -1;

    for (ll t = 1; t <= 3 * n && found < 0; t++) {
        fill(all(dp_curr), INF);  

        for (ll i = 1; i <= n; i++) {
            if (adj[i].empty()) continue;  
            
            ll sz = adj[i].size();
            ll nxt = adj[i][(t - 1) % sz];
            
            dp_curr[i] = min(dp_curr[i], dp_prev[i] + 1);            
            dp_curr[nxt] = min(dp_curr[nxt], dp_prev[i]);

            if (nxt == n && dp_curr[nxt] < INF) {
                found = t;
            }
        }

        swap(dp_prev, dp_curr);
    }

    o2(found, dp_prev[n]);
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