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

void sol(){
    ll n,k;
    i2(n,k);
    vll l(n),r(n);
    for(ll i = 0; i < n; i++) {
        cin >> l[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> r[i];
    }
    vll mx(n), mn(n);
    for(ll i = 0; i < n; i++) {
        mx[i] = max(l[i],r[i]);
        mn[i] = min(l[i],r[i]);
    }
    ll ans = accumulate(mx.begin(),mx.end(),0LL);
    sort(mn.rbegin(),mn.rend());
    for(ll i = 0; i < k-1; i++) {
        ans += mn[i];
    }
    o1(ans+1);
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