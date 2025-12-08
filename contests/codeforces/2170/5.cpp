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

void sol(){
    ll n,m;
    i2(n,m);
    vector<pll> v(m);
    for(ll i=0; i<m; i++){
        i2(v[i].ss,v[i].ff)        
        v[i].ss-=1;
        v[i].ff-=2;
    }
    sort(all(v));
    vector<pll> dp(n);
    if(v[0].ff==0){
        dp[0] = {0,1};
    }
    else dp[0] = {1,1};

    ll itvl_idx=0;
    ll mx_l_idx=0;

    for(ll i=1; i<n-1; i++){
        reach;
        if(i<v[mx_l_idx].ss){
            dp[i].first = (dp[i-1].first+dp[i-1].ss)%MOD;
            dp[i].ss = (dp[i-1].ff+dp[i-1].ss)%MOD;
            continue;
        }
        while(itvl_idx<m && v[itvl_idx].ff<=i){
            if(v[itvl_idx].ss > v[mx_l_idx].ss) mx_l_idx = itvl_idx;
            itvl_idx++;
        }
        cout << "i: " << i << endl;
        if(v[mx_l_idx].ff==i){
            dp[i].first = 0;
            for(ll j=v[i].ss; j<=v[i].ff; j++){
                dp[i].first = (dp[i].first+dp[j].ss)%MOD;                
            }
            dp[i].second = (dp[i-1].ff+dp[i-1].ss)%MOD;
        }
        else{
            
            dp[i].first = (dp[i-1].first+dp[i-1].ss)%MOD;
            dp[i].ss = (dp[i-1].ff+dp[i-1].ss)%MOD;
        }
                
    }

    o1(2*(dp[n-2].ff+dp[n-2].ss));
    
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