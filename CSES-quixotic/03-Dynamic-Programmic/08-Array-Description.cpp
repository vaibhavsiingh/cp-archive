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
    ll n,m;
    i2(n,m);
    vector<ll> v(n);
    iArray(v,n);
    vector<vll> dp(n,vll(m+1));
    if(v[0]==0){
        for(ll i = 1; i <= m; i++) {
            dp[0][i]=1;
        }
    }
    else{
        dp[0][v[0]] = 1;
    }
    // for(ll j = 1; j <= m; j++) {
    //     cout << dp[0][j] << ' ';
    // }
    // o1("");
    for(ll i = 1; i < n; i++) {
        if(v[i]==0){
            for(ll j = 1; j <= m; j++) {
                if(j-1>0) dp[i][j]+=dp[i-1][j-1];
                dp[i][j] +=dp[i-1][j];
                if(j+1<=m) dp[i][j] += dp[i-1][j+1];
                dp[i][j]%=MOD;
            }
        }
        else{
            if(v[i]-1>0) dp[i][v[i]]+=dp[i-1][v[i]-1];
            dp[i][v[i]]+=dp[i-1][v[i]];
            if(v[i]+1<=m) dp[i][v[i]] += dp[i-1][v[i]+1];
            dp[i][v[i]]%=MOD;
        }
        // for(ll j = 1; j <= m; j++) {
        //     cout << dp[i][j] << ' ';
        // }
        // o1("");
    }
    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    o1(ans);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}