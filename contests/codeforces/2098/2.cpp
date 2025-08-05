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

const ll MOD = 1000000007;

void sol() {
    ll n, k;
    cin >> n >> k;
    vll a(n);
    iArray(a, n);
    sort(a.begin(), a.end());

    
    if (k >= n) {
        o1(1000000000);
        return;
    }

    ll Llo = n - k;
    ll Lhi = n;
    
    ll Le = (Llo % 2 == 0 ? Llo : Llo + 1);
    if (Le <= Lhi) {
        
        ll left = a[Le/2 - 1];
        ll right = a[n - Le/2];
        o1(max(0LL, right - left + 1));
    } else {
        ll L = Llo;  
        ll t = (L - 1) / 2;
        ll lidx = t;
        ll ridx = n - 1 - t;

        ll cnt = 0;
        ll prev = LLONG_MIN;
        for (ll i = lidx; i <= ridx; i++) {
            if (a[i] != prev) {
                cnt++;
                prev = a[i];
            }
        }
        o1(cnt);
    }
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
}