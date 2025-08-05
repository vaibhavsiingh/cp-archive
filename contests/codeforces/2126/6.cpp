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

void dfs(ll node, ll parent, const vector<vector<pll>> &adj, vector<ll> &par, vll&cost) {
    par[node] = parent;
    
    for (auto [child,c] : adj[node]) {
        if (child != parent) {
            dfs(child, node, adj, par,cost);
        }
        else{
            cost[node] = c;
        }
    }
}


void sol(){
    ll n,q;
    cin >> n >> q;;
    vll col(n+1);
    for(ll i = 1; i <= n; i++) {
        cin >> col[i];
    }
    vector<vector<pll>> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    vll par(n+1), cost(n+1);
    dfs(1,0,adj,par,cost) ;       

    ll curr_ans = 0;
    ll curr_same = 0;
    vector<map<ll,ll>> m(n+1);
    for(ll i=1; i<=n; i++){
        for(auto [nd,c]:adj[i]){
            if(nd==par[i]) continue;
            m[i][col[nd]]+=c;
            curr_ans += (col[nd]==col[i]) ? 0 : c;
        }
    }

    while(q--){
        ll nd,new_col;
        i2(nd,new_col);
        if(new_col==col[nd]){
            o1(curr_ans);
            continue;
        }
        curr_ans += m[nd][col[nd]] - m[nd][new_col];
        if(col[par[nd]]==col[nd]) curr_ans += cost[nd];
        else if(col[par[nd]]==new_col) curr_ans -= cost[nd];
        m[par[nd]][col[nd]] -= cost[nd];
        m[par[nd]][new_col] += cost[nd];
        col[nd]  = new_col;
        o1(curr_ans);
    }

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