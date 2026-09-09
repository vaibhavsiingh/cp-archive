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
    string s1,s2;
    cin >> s1;
    cin >> s2;

    ll n = s1.length();
    ll m = s2.length();
    vector<vll> dp(n+1, vll(m+1, INF));

    for(ll i=0; i<=m; i++){
        dp[0][i] = i;
    }
    for(ll i=0; i<=n; i++){
        dp[i][0] = i;
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j=1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                //o2(i,j);
                dp[i][j] = dp[i-1][j-1];
            }
            else dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
            
        }
    }
    
    o1(dp[n][m]);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}