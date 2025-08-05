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
    ll n,m;
    i2(n,m);
    vll a(n),b(m);
    iArray(a,n);
    iArray(b,m);
    ll
    vector<bool> dp(100001, false);
    dp[0] = true;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 100000; j >= a[i]; --j) {
            if (dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }
    vector<ll> possible_sums;
    for (ll i = 1; i <= 100000; ++i) {
        if (dp[i]) {
            possible_sums.pb(i);
        }
    }
    oArray(possible_sums, possible_sums.size());
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}