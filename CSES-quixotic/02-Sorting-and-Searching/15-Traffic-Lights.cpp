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
    vll v(x);
    iArray(v,x);
    set<ll> pos;
    pos.insert(0);
    pos.insert(n);
    multiset<ll> dist;
    dist.insert(n);
    for(ll i = 0; i < x; i++) {
        auto itr = pos.lower_bound(v[i]);
        ll r = *(itr--);
        ll l = *(itr);
        dist.erase(dist.find(r-l));
        dist.insert(v[i]-l);
        dist.insert(r-v[i]);
        pos.insert(v[i]);
        cout << *(--dist.end()) << ' ';
    }
    cout << "\n";
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}