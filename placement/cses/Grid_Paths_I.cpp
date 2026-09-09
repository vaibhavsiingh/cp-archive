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
    ll n;
    cin >> n;
    vector<string> grid(n);
    for(ll i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vll> dp(n, vll(n,0));
    if(grid[0][0] == '*') {
        o1(0);
        return;
    }
    dp[0][0] = 1;

    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<n; j++){
            if(grid[i][j] == '*') continue;
            if(i-1 >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
            if(j-1 >= 0) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
        }
    }

    o1(dp[n-1][n-1]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}