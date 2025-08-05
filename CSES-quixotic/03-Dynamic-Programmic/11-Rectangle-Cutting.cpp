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
    ll a,b;
    i2(a,b);
    vector<vll> dp(a+1, vll(b+1));
    for(ll i = 1; i <= a; i++) {
        if(i<=b){
            dp[i][i] = 0;
        }
    }
    for(ll i = 2; i <= a; i++) {
        dp[i][1] = i-1;
    }
    for(ll i = 2; i <= b; i++) {
        dp[1][i] = i-1;
    }
    for(ll i = 2; i <= a; i++) {
        for(ll j=2; j<= b; j++){
            if(i==j) continue;
            ll mn = INT_MAX;
            for(ll p = 1; p<i; p++){
                mn = min(mn,dp[p][j]+dp[i-p][j]);
                

            }
            for(ll p = 1; p<j; p++){
                mn = min(mn,dp[i][p]+dp[i][j-p]);
              //  if(mn==0) o2(i,p);
            }
           // cout << i << ' ' << j << ' ' << mn << endl;
            dp[i][j] = mn+1;
        }
    }
    // for(ll i = 1; i <= a; i++) {
    //     for(ll j=1; j<=b; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    o1(dp[a][b]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}