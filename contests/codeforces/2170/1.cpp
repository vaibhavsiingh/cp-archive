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

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    ll s = n*n-n+1;
    ll mx = 0;
    vector<vll> v(4, vll(n+2));
    for(ll i=1; i<=n; i++){
        v[2][i] = s+i-1;
    }
    s -= n;
    for(ll i=1; i<=n; i++){
        v[1][i] = max((ll)0,s+i-1);
    }
    s-=n;
    for(ll i=1; i<=n; i++){
        v[0][i] = max((ll)0,s+i-1);
    }
    for(ll i = 1; i <= n; i++) {
        mx = max(v[1][i]+v[0][i]+v[2][i]+v[1][i-1]+v[1][i+1], mx);
    }

    for(ll i = 1; i <= n; i++) {
        mx = max(v[2][i]+v[1][i]+v[2][i-1]+v[2][i+1], mx);
    }
    // for(ll i = 0; i < 4; i++) {
    //     for(ll j=0; j<n+2; j++){
    //         cout << v[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    o1(mx);

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