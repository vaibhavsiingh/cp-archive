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

vector<vll> adj;
vector<vll> par;
vll level;
vll path;
vll ans;

void dfs(ll nd, ll p){
    par[nd][0] = p;
    level[nd] = level[p]+1;
    for(ll c: adj[nd]){
        if(c!=p) dfs(c,nd);
    }
}

ll lca(ll a, ll b){
    if(level[a]>level[b]) swap(a,b);
    if(level[a]!=level[b]){
        ll stp = 17;
        while(stp>=0){
            ll nm = (1<<stp);
            if(level[b]-nm>=level[a]){
                b = par[b][stp];
            }
            stp--;
        }
    }
    if(a==b)return a;
    ll stp = 17;
    while(stp>=0){        
        if(par[a][stp]!=par[b][stp]){
            a = par[a][stp];
            b = par[b][stp];
        }
        stp--;
    }
    return par[a][0];
}

ll recurse(ll nd, ll p){
    ll sm = path[nd];
    for(ll c: adj[nd]){
        if(c!=p) sm += recurse(c,nd);
    }
    ans[nd] = sm;
    return sm;
}

void sol(){
    ll n,m;
    cin >> n >> m;
    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    par.resize(n+1, vll(18));
    level.resize(n+1);
    dfs(1,0);

    for(ll t=1; t<18; t++){
        for(ll nd=1; nd<=n; nd++){
            par[nd][t] = par[par[nd][t-1]][t-1];
        }
    }
    path.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        path[x]++;
        path[y]++;
        ll lca_xy = lca(x,y);
        path[lca_xy]--;
        path[par[lca_xy][0]]--;
        
    }
    ans.resize(n+1);
    recurse(1,0);
    for(ll i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    o1("");


}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}