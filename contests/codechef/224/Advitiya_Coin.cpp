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
#define o2(a, b) cout << a << ' ' << b << "\n"
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;
void sol() {
    ll n, k;
    cin >> n >> k;

    vll a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll i = 0;
    ll mn = INT_MAX, mx = INT_MIN;
    ll cnt = 0;
    for(; i<n; i++){
        for(; i<n; i++){
            //o2(mn,mx);
            //o1(a[i]);
            if(a[i]-mn -k > 0 || mx - a[i]-k >0){
                cnt++;
                mn = INT_MAX, mx = INT_MIN;
                break;
            }
            mn = min(mn,a[i]);
            mx = max(mx,a[i]);
        }
    }
    o1(cnt);
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