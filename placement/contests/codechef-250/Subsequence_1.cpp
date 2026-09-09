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

void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);

    vector<pll> dp(n);
    vector<vll> last_seen(n+1);
    if(a[0]==1){
        dp[0] = {1,1};
    }
    else{
        dp[0] = {0,0};
    }
    last_seen[a[0]].push_back(0);

    for(ll i=1; i<n; i++){
        ll ls = -1;
        if(last_seen[a[i]].size() > 0) ls = last_seen[a[i]].back();
        if(a[i]==1){
            ll better = max(dp[i-1].ff, dp[i-1].ss);
            dp[i] = {better+1, better+1};
        }
        else{
            for(ll idx=last_seen[a[i]-1].size()-1; idx >= 0; idx--){
                ll pos = last_seen[a[i]-1][idx];
                if(pos < ls) break;
                if(dp[pos].ff > 0){
                    dp[i].ff = dp[pos].ff +1;
                    break;
                }
                else{
                    dp[i].ff = 0;
                }
            }
            dp[i].ss = max(dp[i-1].ff, dp[i-1].ss);
        }
        
        last_seen[a[i]].push_back(i);
    }
    // for(auto [x,y]: dp){
    //     o2(x,y);
    // }
    o1(max(dp[n-1].ff,dp[n-1].ss));
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