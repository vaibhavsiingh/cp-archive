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

void calculate(ll y, int nd, vector<vll>& adj, vector<pll>& dp, vll& ybranch, vll& dist, int n, int p){
    if(nd == y){
        ybranch[nd] = 1;
    }
    
    if(adj[nd].size() == 1 && adj[nd][0] == p){
        dp[nd] = {0,0};
        return;
    }

    int sm = 0;
    for(ll nxt: adj[nd]){
        if(nxt != p){
            dist[nxt] = dist[nd]+1;
            calculate(y, nxt, adj, dp, ybranch, dist,n, nd);
            ybranch[nd] |= ybranch[nxt];
            sm += dp[nxt].first+2;            
        }
    }
    ll mn = 1e5;
    for(ll nxt: adj[nd]){
        if(nxt != p){
            mn = min(mn, sm - dp[nxt].first - 1 + dp[nxt].second);
        }
    }
    dp[nd] = {sm, mn};
}

void sol(){
    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;

    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);        
    }

    vector<pll> dp(n+1);
    vector<ll> dist(n+1, INF);
    vll ybranch(n+1,0);
    dist[x] = 0;
    calculate(y, x, adj, dp, ybranch, dist, n, -1);
    
    

    ll ans1 = 0;
    ll mn = INF;
    ll ans2 = 0;
    for(ll nxt : adj[x]){
        if(!ybranch[nxt]){
            mn = min(mn, dp[x].first - dp[nxt].first - 1 +dp[nxt].second);            
        }
        else{
            ans2 = dp[x].first - dp[nxt].first - 1 + dp[nxt].second + dist[y];
        }

    }
    ans1 = mn;
    if(dist[y]%2) ans1++; 
    o1(min(ans1,ans2));

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