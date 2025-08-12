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
#define sz size()
#define o1(a) cout << a << "\n"
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    if(!(cin >> t)) return 0;
    while(t--){
        ll n;
        cin >> n;
        vector<vll> adj(n+1);
        vector<ll> deg(n+1, 0);
        for(ll i = 0; i < n-1; i++){
            ll x,y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
            deg[x]++; deg[y]++;
        }

        
        vector<int> is_leaf(n+1, 0);
        ll L = 0;
        for(ll v = 1; v <= n; v++){
            if(deg[v] == 1){
                is_leaf[v] = 1;
                L++;
            }
        }

        ll best = 0;
        for(ll v = 1; v <= n; v++){
            ll S = is_leaf[v];
            for(auto u: adj[v]) S += is_leaf[u];
            best = max(best, S);
        }

        ll ans = L - best;
        if(ans < 0) ans = 0;
        o1(ans);
    }
    return 0;
}
