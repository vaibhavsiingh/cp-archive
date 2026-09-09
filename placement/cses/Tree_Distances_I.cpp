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
    ll n;
    cin >> n;
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<vll> dist(n+1);
    auto recurse = [&](auto&& self, int nd, int par) -> int{
        if(adj[nd].size() == 1 && adj[nd][0] == par){
            dist[nd].pb(-1);
            return 0;
        }
        ll mx  = 0;
        for(ll nxt: adj[nd]){
            if(nxt == par){
                dist[nd].pb(-1);
                continue;
            }
            ll d = self(self, nxt, nd) +1; 
            mx = max(mx, d);
            dist[nd].push_back(d);
        }
        return mx;
    };

    recurse(recurse, 1, -1);

    // for(ll i = 0; i < n; i++) {
    //     for(ll x: dist[i+1]){
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }

    vll ans(n+1);
    auto recurse2 = [&](auto&& self, int nd, int par, int mx_without_nd) -> void{
        if(adj[nd].size() == 1 && adj[nd][0] == par){
            ans[nd] = mx_without_nd + 1;
            return;            
        }
        ll mx_nd = -1;
        ll mx  = mx_without_nd+1;
        ll mx2 = 0;
        for(ll i=0; i<adj[nd].size(); i++){
            ll nxt = adj[nd][i];
            if(nxt == par){                
                continue;
            }  
            ll curr = dist[nd][i];
            if(curr >= mx){
                mx2 = mx;
                mx = curr;
                mx_nd = nxt;
            }
            else if(curr > mx2){
                mx2 = curr;
            }
        }
        ans[nd] = mx;
        for(ll nxt: adj[nd]){
            if(nxt != par){
                if(nxt == mx_nd){
                    self(self, nxt, nd, mx2);
                }
                else self(self, nxt, nd, mx);
            }
        }
        return;
    };

    recurse2(recurse2, 1, -1, -1);

    for(ll i = 0; i < n; i++) {
        cout << ans[i+1] << ' ';
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}