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
    ll n,q;
    i2(n,q);
    vll a(n);
    iArray(a,n);
    vll pre_sum(n);
    pre_sum[0] = a[0];
    for(ll i = 1; i < n; i++) {
        pre_sum[i] = pre_sum[i-1]+a[i];
    }
    while(q--){
        ll x,y;
        i2(x,y);
        x--;y--;
        o1(pre_sum[y]-pre_sum[x]+a[x]);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}