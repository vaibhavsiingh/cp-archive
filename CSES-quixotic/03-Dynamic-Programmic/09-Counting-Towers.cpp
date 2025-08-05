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

void sol(){
    ll t;
    cin >> t;
    vll aa(t);
    iArray(aa,t);
    ll mx = *max_element(aa.begin(),aa.end());
    vector<pll> dp(mx+1);
    dp[1] = {1,1};
    for(ll i = 2; i <= mx; i++) {
        dp[i].ff = (dp[i-1].ss + 4*dp[i-1].ff)%MOD;
        dp[i].ss = (dp[i-1].ff + 2*dp[i-1].ss)%MOD;
    }
    for(ll i = 0; i < t; i++) {
        o1((dp[aa[i]].ff + dp[aa[i]].ss)%MOD);
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}