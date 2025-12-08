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

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);

    vll gcdl(n),gcdr(n);
    gcdl[0] = a[0];
    gcdr[n-1] = a[n-1];

    for(ll i=1; i<n; i++){
        gcdl[i] = gcd(gcdl[i-1],a[i]);

    }

    for(ll i=n-2; i>=0; i--){
        gcdr[i] = gcd(gcdr[i+1],a[i]);
    }

    ll cost = 0;
    for(ll i = 1; i < n; i++) {
        cost += min(gcdl[i],gcdr[i]);
    }

    o1(cost);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}