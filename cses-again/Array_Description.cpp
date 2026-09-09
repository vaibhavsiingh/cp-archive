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
    ll n,m;
    cin >> n >> m;
    vll a(n);
    iArray(a,n);

    vector<vll> dp(n, vll(m+1,0));

    if(a[0] == 0){
        dp[0] = vector<ll>(m+1,1);        
        dp[0][0] = 0;
    }
    else{
        dp[0][a[0]] = 1;
    }

    for(ll i=1; i<n; i++){
        if(a[i] != 0){
            if(a[i] != 1) dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]-1]) % MOD;
            dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]]) % MOD;
            if(a[i] != m) dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][a[i]+1]) % MOD;
        }
        else{
            dp[i][m] = (dp[i][m] + dp[i-1][m-1]) % MOD;
            dp[i][m] = (dp[i][m] + dp[i-1][m]) % MOD;
            for(ll j=2; j<=m-1; j++){
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
                dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % MOD;
            }
            dp[i][1] = (dp[i][1] + dp[i-1][1]) % MOD;
            dp[i][1] = (dp[i][1] + dp[i-1][2]) % MOD;
        }        
    }

    ll ans = 0;
    for(ll i = 1; i <= m; i++) {
        ans = (ans + dp[n-1][i]) % MOD;
    }
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}