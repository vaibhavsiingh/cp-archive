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
    ll n;
    cin >>n;
    vector<pll> v(2*n);
    for(ll i = 0; i < 2*n; i+=2) {
        ll x,y ;
        cin >> x >> y;
        v[i] = {x,1};
        v[i+1] = {y,-1};
    }
    
    sort(v.begin(),v.end());
    ll mx=0;
    ll curr = 0;
    for(int i=0; i<2*n; i++){
      //  o1(v[i].ss);
        curr += v[i].ss;
        mx = max(mx,curr);
    }
    o1(mx);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}