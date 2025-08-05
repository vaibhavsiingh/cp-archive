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
    string s1, s2;
    cin >> s1 >> s2;
    ll n = s1.size(), m = s2.size();
    vector<vll> dp(n+1,vll(m+1));

    for(ll i = 0; i <= n; i++) {
        for(ll j=0; j<=m; j++){
            if(i==0){
                dp[0][j] = j;
            }
            else if(j==0){
                dp[i][0] = i;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }
    // for(ll i = 0; i < n; i++) {
    //     for(ll j=0; j<m; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    o1(dp[n][m]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}