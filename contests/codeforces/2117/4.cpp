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

ll gcd(ll a,ll b){
    return b == 0 ? a : gcd(b, a % b);
}

void sol(){
    ll n;
    cin >> n;
    vll v(n);
    iArray(v,n);
    v.insert(v.begin(),0);
    ll ans = 1;
    ll x = (2*v[1]-v[2])/(n+1), y = v[2]-v[1]+x;
    if(((2*v[1]-v[2]))%(n+1)!=0 || x<0 || y<0){
        ans=0;
     //   o2(((2*v[1]-v[2]))%(n+1),((n+2)*v[2]-(n+1)*v[1])%(n+1));
        o1("NO");
        return;
    }
    for(int i=2; i<n; i++){
        ll xdash= ((i+1)*v[i]-i*v[i+1])/(n+1), ydash = v[i+1]-v[i]+xdash;
        if(xdash!=x || ydash!=y || ((i+1)*v[i]-i*v[i+1])%(n+1)!=0){
          //  o1(i);
            o1("NO");
            return;
        }
    }
    o1("YES");
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