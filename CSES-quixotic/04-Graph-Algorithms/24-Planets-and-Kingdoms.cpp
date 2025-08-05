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

vll visited;

void dfs(ll n, vector<vll>& adj, vll& order){
    visited[n] = 1;
  //  o1(n);
    for(ll x:adj[n]){
        if(!visited[x])
        dfs(x,adj,order);
    }
    order.pb(n);
}

void sol(){
    ll n,m;
    i2(n,m);
    visited.resize(n+1,0);
    vector<vll> adj(n+1), adj_rev(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj_rev[y].pb(x);
    }
    
    vll order;
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            dfs(i,adj,order);
        }
    }

    visited.assign(n+1,0);
    reverse(order.begin(),order.end());

    ll count=1;
    vll planet2kingdom(n+1);
    
    for(ll nd:order){
        if(!visited[nd]){
            vll component;
            dfs(nd,adj_rev,component);
            for(ll y:component){
                planet2kingdom[y] = count;
            }
            count++;
         //   reach;
        }
    }
    o1(--count);
    for(ll i = 1; i <= n; i++) {
        cout << planet2kingdom[i] << ' ';
    }
    cout << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}