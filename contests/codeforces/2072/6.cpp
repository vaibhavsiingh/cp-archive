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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << "\n";

const ll MOD = 1000000007;

void sol(){
    ll n, k;
    i2(n, k);
    vector<ll> row  ;
    row.reserve(n);
    int mask = n - 1; 
    
    for (int j = 1; j <= n; ++j) {
        if (((j - 1) & mask) == (j - 1)) {
            row.push_back(k);
        } else {
            row.push_back(0);
        }
    }
    oArray(row, row.size());
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}
