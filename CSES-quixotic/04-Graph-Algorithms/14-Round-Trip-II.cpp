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
vector<vector<ll>> adj;
vll parent;
vll visited;
ll cycle_start, cycle_end;

ll dfs(ll n){
    visited[n] = 1;
    for(ll nxt:adj[n]){
        if(visited[nxt]==0){
            parent[nxt] = n; 
            ll x = dfs(nxt);
            if(x) return 1;
        }
        else if(visited[nxt]==1){
            cycle_end = n;
            cycle_start = nxt;
            return 1;
        }
    }
    visited[n] = 2;
    return 0;
}

void sol(){
    cin >> n >> m;
    adj.resize(n+1);
    parent.resize(n+1,-1);
    visited.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
    }


    ll final_node = -1;
    //o2(n,m);
    //reach;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            parent[i]=0;
            ll x = dfs(i);
            if(x){
                final_node  = x;
                break;
            }
        }
    }
    if(final_node==-1){
        o1("IMPOSSIBLE");
        return;
    }
//     set<ll> s;
//     ll curr = final_node;
//    // oArray(parent,n+1);
//     while(!s.count(curr) && curr!=-1){
//       //  o1(curr);
//         s.insert(curr);
//         curr = parent[curr];   
//     }
//     if(curr==-1){
//         o1("FUCK");
//         return;
//     }

    vll path;
    path.pb(cycle_start);
    for (ll v = cycle_end; v != cycle_start; v = parent[v])
        path.pb(v);
    path.pb(cycle_start);
    reverse(path.begin(), path.end());

    o1(path.size());
    oArray(path, path.size());
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}