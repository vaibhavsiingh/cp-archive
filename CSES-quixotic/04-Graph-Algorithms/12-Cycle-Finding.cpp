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
vector<vll> edges;
vll dfsv;

void dfs(int node){
    if(dfsv[node]) return;
    dfsv[node] =1;
    for(ll child:adj[node]){
        dfs(child);
    }
}

void sol(){
    i2(n,m);
    adj.resize(n+1);
    edges.resize(m);
    dfsv.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb(y);
        edges[i] = {x,y,z};
    }
    vll parent(n+1,-1);
    vll dist(n+1,1e14);
    //dist[1] = 0;
    ll last = -1;
    for(int i=1; i<=n; i++){
        if(!dfsv[i]){
            dist[i] = 0;
            dfs(i);
        }
    }
    for(int i=0; i<n; i++){
        last = -1;
        for(int j=0; j<m; j++){
            ll x=edges[j][0], y = edges[j][1], wt = edges[j][2];
            if(dist[x]!=1e14 && dist[x]+wt<dist[y]){
                dist[y] = dist[x]+wt;
                
                last = y;
                parent[y] = x;
                
            }
        }
    }
    if(last<0){
        o1("NO");
        return;
    }
    o1("YES");
   // ll start=1;
  //  while(parent[start]==-1) start++;
 //   cout << "start: " << start << endl;

    for (int i = 0; i < n; i++){
        last = parent[last];
    }
    set<ll> visited;
    vll nds;
    while(!visited.count(last)){
    //    cout << "start: " << start << endl;
        nds.pb(last);
        visited.insert(last);
        last = parent[last];
    }
    cout << last << ' ';
    ll ptr = nds.size()-1;
    while(nds[ptr]!=last){
        cout << nds[ptr] << ' ';
        ptr--;
    }
    cout << last << '\n';


}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}