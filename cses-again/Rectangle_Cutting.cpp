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
    ll a,b;
    cin >> a >> b;
    if(a> b){
        swap(a,b);
    }
    vector<vll> dp(a+1, vll(b+1, INF));

    for(ll xa=1; xa<=a; xa++){
        for(ll xb=1; xb<=b; xb++){
            if(xa > xb ){
                dp[xa][xb] = dp[xb][xa];
                continue;
            }
            if(xa==xb){
                dp[xa][xb] = 0;
                continue;
            }
            ll mn = INF;
            for(ll acut=1; acut<xa; acut++){
                assert(xa-acut > 0);
                assert(xa-acut <= a);
                mn = min(mn, dp[acut][xb]+dp[xa-acut][xb]+1);
            }
            for(ll bcut=1; bcut<xb; bcut++){
                assert(xb-bcut > 0);
                assert(xb-bcut <= b);
                mn = min(mn, dp[xa][bcut]+dp[xa][xb-bcut]+1);
            }
            dp[xa][xb] = mn;
        }
    }
    // for(ll i = 1; i  <= a+1; i++) {
    //     for(ll j=1; j<=b; j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    o1(dp[a][b]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}