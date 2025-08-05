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
    cin >> n;
    vll a(n);
    iArray(a,n);
    set<ll> bad_indices;
    for(ll i = 0; i < n; i++) {
        if(a[i]!=i%2) {
            bad_indices.insert(i);
        }
    }
    ll q;
    cin >> q;
    while(q--){
        ll p,x;
        i2(p,x);
        p--;
        if(bad_indices.count(p) && x!=a[p]){
            bad_indices.erase(p);
        }
        else if(!bad_indices.count(p) && x!=a[p]){
            bad_indices.insert(p);
        }
        a[p] = x;
        if(bad_indices.size()>0){
            auto oo = bad_indices.end();
            oo--;
            //o2("krazy: ",*oo);
            o1(a[*oo]);
        }
        else{
            o1(0);
        }
        
        
        
    }
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