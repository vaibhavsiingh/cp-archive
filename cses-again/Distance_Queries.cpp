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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n,q;
    cin >> n >> q;

    vector<vll> adj(n+1);
    
    for(ll i = 0; i < n-1; i++) {
        ll a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vector<vll> dp(n+1, vll(20));
    vll level(n+1,0);

    auto fillStuff = [&](auto&& self, int nd, int par) -> void{
        for(ll nxt: adj[nd]){
            if(nxt != par){
                dp[nxt][0] = nd;
                level[nxt] = level[nd]+1;
                self(self, nxt, nd);
            }
        }
    };

    fillStuff(fillStuff, 1, -1);
    
    for(ll l=1; l<20; l++){
        for(ll nd=1; nd<=n; nd++){
            dp[nd][l] = dp[dp[nd][l-1]][l-1];
        }
    }
    
    while(q--){
        ll a,b;
        cin >> a >> b;

        if(level[a] > level[b]){
            swap(a,b);
        }

        ll to_lift = level[b] - level[a];
        
        for(ll idx=0; idx<20; idx++){
            if(to_lift & (1<<idx)){
                b = dp[b][idx];
            }
        }
        
        if(a==b){
            o1(to_lift);
            continue;
        }
        
        ll lifted = 0;
        for(ll idx=19; idx>=0; idx--){
            if(dp[a][idx] != dp[b][idx]){
                a = dp[a][idx];
                b = dp[b][idx];
                lifted += (1<<idx);
            }
        }
        
        o1(2*lifted+2 + to_lift);

    }

    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}