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

const ll MOD = 1000000007;

ll n,m;
vll visited;

void dfs(vector<vll>& adj, ll nd, vll& order){
    visited[nd] = 1;
   // o1(nd);
    for(auto chd:adj[nd]){
        if(!visited[chd])
        dfs(adj, chd, order);
    }
    order.pb(nd);
}

void sol(){
    i2(n,m);
    vector<vll> adj;
    vll order;
    adj.resize(n+1);
    visited.resize(n+1);
    visited.assign(n+1, 0);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
    }

    dfs(adj, 1, order);
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            o1("NO");
            o2(1,i);
            return;
        }
    } 

    vector<vll> adj_T(n+1);
    for(ll i=1; i<n+1; i++){
        for(auto x:adj[i]){
            adj_T[x].pb(i);
        }
    }
    
    visited.assign(n+1,0);
    vll temp;
    reverse(order.begin(),order.end());
    dfs(adj_T,order[0], temp);
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            o1("NO");
            o2(i,order[0]);
            return;
        }
    }
    o1("YES");

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}