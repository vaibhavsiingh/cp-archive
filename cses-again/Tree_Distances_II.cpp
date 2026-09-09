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

    vector<vll> cnt(n+1);
    vll dist1(n+1);
    auto recurse = [&](auto&& self, int nd, int par) -> int{
       
        if(adj[nd].size() == 1 && adj[nd][0] == par){
            if(nd!=1) dist1[nd] = dist1[par]+1;
            cnt[nd].pb(-1);
            return 1;
        }
        ll sm  = 1;
        
        if(nd!=1) dist1[nd] = dist1[par]+1;
        
        for(ll nxt: adj[nd]){
            if(nxt == par){
                cnt[nd].pb(-1);
                continue;
            }
            ll c = self(self, nxt, nd); 
            sm  += c;
            cnt[nd].push_back(c);
        }
        return sm;
    };

    recurse(recurse, 1, -1);
    //oArray(dist1, n+1);

    ll total_dist1 = accumulate(all(dist1), 0ll);

    vll ans(n+1);
    ans[1] = total_dist1;

    auto recurse2 = [&](auto&& self, int nd, int par, int count) -> void{
        ll reduced = count;
        ll increased = n-count;
        ans[nd] = ans[par] - reduced + increased;

        for(ll i=0; i<adj[nd].size(); i++){
            ll nxt = adj[nd][i];
            if(nxt == par){
                continue;
            }
            self(self, nxt, nd, cnt[nd][i]);
        }
    };

    for(ll i=0; i<adj[1].size(); i++){
        ll nxt = adj[1][i];
        recurse2(recurse2, nxt, 1, cnt[1][i]);
    }

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