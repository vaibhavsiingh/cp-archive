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
vector<vll> adj;
vll visited;
vll parent;

ll dfs(ll start,ll p){
    if(visited[start]){
        return start;
    }
  //  o2("Currently visiting: ", start);
    visited[start] = 1;
    for(ll nxt:adj[start]){
        if(nxt==p) continue;
        parent[nxt] = start;
        ll x = dfs(nxt,start);
        if(x!=-1)return x;
    }
    return -1;
}

void sol(){
    cin >> n >> m;
    adj.resize(n+1);
    parent.resize(n+1);
    visited.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            ll x =dfs(i,-2);
            
            // for(ll i = 1; i < n+1; i++) {
            //     cout << parent[i] << ' ';
            // }
            
            // cout << endl;
            if(x!=-1){
                stack<ll> path;
                ll ptr = parent[x];
                path.push(x);
                while(ptr!=x){
                    path.push(ptr);
                    ptr = parent[ptr];
                }
                path.push(x);
                
                o1(path.size());
                while(!path.empty()){
                    cout << path.top() << ' ';
                    path.pop();
                }
                cout << "\n";
                return;
            }
        }
    }
    o1("IMPOSSIBLE");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}