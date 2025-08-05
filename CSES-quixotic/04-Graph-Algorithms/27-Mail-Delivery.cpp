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

vector<vector<pll>> adj;
ll n,m;
vector<int> visited(m);
vector<int> order;

void dfs(int nd){
    //cout << "nd " << nd << endl;
    while(adj[nd].size()>0){
        auto [x,idx] = adj[nd].back();
        if(!visited[idx]){
            visited[idx] = 1;
            adj[nd].pop_back();
            dfs(x);
        }
        else adj[nd].pop_back();
    }
    order.push_back(nd);
}

void sol(){
    
    cin >> n >> m;
    adj.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].push_back({y,i});
        adj[y].push_back({x,i});
    }
    for(ll i = 1; i <= n; i++) {
        if(adj[i].size()%2){
            o1("IMPOSSIBLE");
            return;
        }
    }

    visited.resize(m,0);
    stack<int> stk;
    dfs(1);
    if(accumulate(all(visited),0)!=m){
        o1("IMPOSSIBLE");
        return;
    }
    oArray(order,order.size());
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}