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

const ll MOD = 998244353;


void bfs(vector<vll>&adj, vector<pll>& dist){
    queue<ll> q;
    q.push(1);
    dist[1].ff = 0;
    dist[1].ss = 1;
    while(!q.empty()){
        ll nd = q.front();
        q.pop();
        for(ll child:adj[nd]){
            dist[child].ff = dist[nd].ff+1;
            dist[child].ss = child;
            q.push(child);
        }
    }

}

void sol(){
    ll n;
    cin >> n;
    vll p(n-1);
    iArray(p,n-1);
    vector<vll> adj(n+1);

    for(int i=0; i<n-1; i++){
        adj[p[i]].pb(i+2);
    }
    // for(int i=1; i<n+1; i++){
    //     o2("Children of node ",i);
    //     for(auto x:adj[i]){
    //         cout << x << ' ';
    //     }
    //     o1("");
    // }

    p.insert(p.begin(),0);
    p.insert(p.begin(),0);
   // oArray(p,p.size());

    vector<pll> dist(n+1);
    bfs(adj,dist);
  //  sort(dist.begin(),dist.end());
    // for(int i=1; i<n+1; i++){
    //     o2(dist[i].ss,dist[i].ff );
    // }

    map<ll,vll> m;
    for(int i=1; i<=n; i++){
        m[dist[i].ff].pb(dist[i].ss);
    }
    
    // for(auto itr = m.begin(); itr!=m.end(); itr++){
    //     o2("Dist ",itr->first);
    //     oArray(itr->second,(itr->second).size());
    // }
    vll dp(n+1);
    ll mxD = m.rbegin()->first;
    for(auto x:m[mxD]) dp[x]=1;
    for(ll d=mxD-1; d>=0; d--){
        ll sum=0;
        for(auto x:m[d+1]){
            sum=(sum+dp[x])%MOD;
        }
        if(d==0){
            dp[1] = (sum+1)%MOD;
            break;
        }
        for(auto x:m[d]){
            ll dis=0;
            for(auto chd:adj[x]){
                dis=(dis+dp[chd])%MOD;
            }
            dp[x]=(MOD+sum-dis+1)%MOD;
        }
    }
  //  oArray(dp,n+1);
    o1(dp[1]);
    
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
}