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
    ll n,m,k,w;
    cin >> n >> m >> k >> w;
    ll a[w];
    for(ll i = 0; i < w; i++) {
        cin >> a[i];
    }
vector<ll> ss;
    
    for(ll x = 0; x < n; x++) {
        for(ll y = 0; y < m; y++) {
            ll sx = max(-1LL, x - k);
            ll ex = min(x, n-k);
            ll sy = max(-1LL, y - k);
            ll ey = min(y, m-k);
            ss.pb((ex - sx) * (ey - sy));
        }
    }
    sort(ss.begin(), ss.end());
    sort(a,a+w);
    //oArray(ss,n*m);
    ll ans = 0;
    ll ptr = n*m-1;
    for(int i=w-1; i>=0; i--){
        ans += a[i]*ss[ptr];
        ptr--;
    }
    o1(ans);
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