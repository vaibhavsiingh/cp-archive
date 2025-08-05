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
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);    
    vector<vll> v(k+1);
    for(ll i = 0; i < n; i++) {
        v[a[i]].pb(i);
    }
    vll dp(n);
    
    for(ll i=k-1; i>=1; i--){
        for(auto x:v[i]){
            ll r = (lower_bound(all(v[i+1]),x)-v[i+1].begin());
            ll l = r-1;
            ll real_l = v[i+1][l], real_r = v[i+1][r];
            if(l<0){
                dp[x] = dp[real_r]+abs(real_r-x);
            }
            else if(r==v[i+1].size()) dp[x] = x-real_l+dp[real_l];
            else dp[x] = min(x-real_l+dp[real_l],real_r-x+dp[real_r]);
        }
    }

    vll ans(n);
    ll m = v[1].size();
    for(ll i = 0; i < n; i++) {
        ll l = lower_bound(all(v[1]),i)-v[1].begin();
        ll real_idx = v[1][l];
        if(l==m){
            ans[i] = dp[v[1][m-1]]+i-v[1][m-1];
        }
        else if(l==0)ans[i] = dp[v[1][0]]+v[1][l]-i;
        else{
            ans[i] = min(dp[real_idx]+real_idx-i,dp[v[1][l-1]]+i-v[1][l-1]);
        }
    }
    oArray(ans,n);
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