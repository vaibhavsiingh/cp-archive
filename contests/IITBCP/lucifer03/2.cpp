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
#define all(x) x.begin(), x.end()

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n,k;
    i2(n,k);
    vll a(n), b(n);
    iArray(a,n);
    iArray(b,n);

    vector<pll> c(n);
    for(ll i = 0; i < n; i++) {
        c[i].ff = a[i]-b[i];
        c[i].ss = i;
    }
    sort(all(c));
    ll item=0;
    ll cost=0;
    while(item<n && (item<k || c[item].ff<=0)){
        cost+=a[c[item].ss];
        item++;
    }
    while(item<n){
        cost+=b[c[item].ss];
        item++;
    }
    o1(cost);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}