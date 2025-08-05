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
    ll m,n;
    i2(m,n);
    vll f(m);
    f[0] = 1; f[1] = 2;
    for(ll i = 2; i < m; i++) {
        f[i] = f[i-1]+f[i-2];
    }
    ll l=f[m-1],sl = f[m-2];
    for(ll ii = 0; ii < n; ii++) {
        vll a(3);
        iArray(a,3);
        ll i = min_element(all(a)) - a.begin();
        ll j = max_element(all(a)) - a.begin();
       // o2(a[i],l);
        if(a[i]>=l && a[j]>=l+sl) cout << 1;
        else cout << 0;
    }
    cout << '\n';
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