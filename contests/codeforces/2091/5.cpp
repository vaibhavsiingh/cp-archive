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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<vector<vll>>> dp(n+1, vector<vector<vll>>(n+1, vector<vll>(n+1, vll(n+1))));
    for(ll i=0; i<n; i++){
        for(ll b=0; b<=n; b++){
            for(ll l=0; l<n; l++){
                for(ll d=0; d<4; d++){
                    dp[i][b][l][d] += dp[i-1][b][l][d];                    
                }
                if(s[i]=='(' && b<n){
                    dp[i][b+1][l+1][0] += dp[i-1][b][l][0];
                    dp[i][b+1][l+1][2] += dp[i-1][b][l][1];
                    dp[i][b+1][l+1][3] += dp[i-1][b][l][2];
                    dp[i][b+1][l+1][3] += dp[i-1][b][l][3];
                }
                else if(b>0){                    
                    dp[i][b-1][l+1][1] += dp[i-1][b][l][0];
                    dp[i][b-1][l+1][1] += dp[i-1][b][l][1];
                    dp[i][b-1][l+1][2] += dp[i-1][b][l][2];
                    dp[i][b-1][l+1][3] += dp[i-1][b][l][3];
                }
            }
        }
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        for(ll l=2; l<n; l++){
            ans = (ans+(dp[i][0][l][3]*(n-2)%MOD))%MOD;
        }
    }
    o1(ans);
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