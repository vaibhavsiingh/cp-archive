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

const ll MOD = 998244353;
const ll INF = 1e18;

ll n;
vector<vll> adj;

ll countLoop(ll nd, vector<ll>& waysLoop, ll par, vll& parent){    
    
    if(adj[nd].size()==1 && nd!=1) {        
        waysLoop[nd] = 1;
        parent[nd] = par;
        return 1;
    }
    ll sm = 1;
    parent[nd] = par;
    
    for(ll i=0; i<adj[nd].size(); i++){
        ll chd = adj[nd][i];
        if(chd!=par){
            
            sm = (countLoop(chd, waysLoop, nd, parent)+sm)%MOD;
        }
    
    }
    waysLoop[nd] = sm;
    return sm;
}


void sol(){
    
    cin >> n;
    adj.clear();
    adj.resize(n+1);
    for(ll i=0; i<n-1; i++){
        ll x,y;
        cin >> x >> y;        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    vll waysLoop(n+1);
    vll par(n+1);
    
    countLoop(1, waysLoop, -1, par);
    
    vll path = {n};
    // oArray(par,n+1);
    // oArray(waysLoop, n+1);
    while(path.back()!=1){
        path.push_back(par[path.back()]);
    }
    reverse(all(path));
    vector<vll> dp(path.size(), vll(2));
    //oArray(waysLoop, n+1);
//oArray(path,path.size());
    dp[0][0] = (waysLoop[path[0]] - waysLoop[path[1]]-1+MOD)%MOD;
    dp[0][1] = 1;
    ll ans = 1;
   // o2(dp[0][0], dp[0][1]);
    for(ll i=1; i<path.size()-1; i++){
        ll nd = path[i];
        dp[i][0] = ((((dp[i-1][1]+dp[i-1][0])%MOD)*((waysLoop[nd]-waysLoop[path[i+1]]-1+MOD)%MOD))%MOD + dp[i-1][1])%MOD;
        dp[i][1] = (dp[i-1][1]+dp[i-1][0])%MOD;
      //  o2(dp[i][0], dp[i][1]);
    }
    ll np = path.size(); 
    o1((dp[np-2][0]+dp[np-2][1])%MOD);
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