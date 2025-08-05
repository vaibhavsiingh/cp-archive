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
    ll n,m;
    i2(m,n);
    vll a(m),b(n);
    iArray(a,m);
    iArray(b,n);
    multiset<ll> s;
    for(ll i = 0; i < m; i++) {
        s.insert(a[i]);
    }
    for(ll i = 0; i < n; i++) {
        auto l = s.lower_bound(b[i]);
        auto u = s.upper_bound(b[i]);
        if(l==u && l!=s.begin()){
            l--;
            o1(*l);
            s.erase(l);
        }
        else if(l!=u){
            o1(*l);
            s.erase(l);
        }
        else{
            o1(-1);
        }

    }

    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}