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
    ll n,x;
    i2(n,x);
    vector<ll> v(n);
    iArray(v,n);
    vll prefix(n);
    prefix[0] = v[0];
    for(ll i = 1; i < n; i++) {
        prefix[i] = prefix[i-1]+v[i];
    }
    ll ans = 0;
    map<ll,ll> m;
    m[0] = 1;
    for(ll i = 0; i < n; i++) {
        ans+=m[prefix[i]-x];
        m[prefix[i]]+=1;    
    }
    o1(ans);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}