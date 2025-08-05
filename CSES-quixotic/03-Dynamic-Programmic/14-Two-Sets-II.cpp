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
    ll n;
    cin >> n;
    ll sm = ((n)*(n+1))/2;
    if(sm%2) {
        o1(0);
        return;
    }
    sm/=2;
    vll dp(sm+1);
    dp[0] = 1;
    for(ll i = 1; i < n; i++) {
        for(ll j=sm; j>=i; j--){
            dp[j]=(dp[j]+dp[j-i])%MOD;
        }
    }
    o1(dp[sm]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}