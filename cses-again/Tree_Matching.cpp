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
    ll n;
    cin >> n;
    if(n==1){
        o1(0);
        return;
    }
    vector<vll> adj(n);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        --x;--y;
        adj[x].pb(y);
        adj[y].pb(x);    
    }

    vector<vll> dp(n, {0,0});

    auto recurse = [&](auto&& self, int nd, int par) -> void{
        if(adj[nd].size() == 1 && adj[nd][0] == par){
            return;
        }        
        ll use_all = 0;
        for(auto c: adj[nd]){
            if(c==par) continue;
            self(self, c, nd);                        
            use_all += dp[c][0];
        }
        dp[nd][1] = use_all;
        for(auto c: adj[nd]){
            if(c==par) continue;
            dp[nd][0] = max(1 + dp[c][1] + use_all - dp[c][0], dp[nd][0]);
        }
    };

    recurse(recurse, 0, -1);
    o1(max(dp[0][0], dp[0][1]));
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}