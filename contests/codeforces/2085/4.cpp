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
    vll v(n);
    iArray(v,n);
    ll free=0;
    multiset<ll> used;
    used.insert(v[n-1-k]);
    for(ll i=n-2-k; i>=0; i--){
      //  o2(free, v[i]);
        if(free==k){
            used.insert(v[i]);
           // o2("added",v[i]);
            free=0;
            continue;
        }
        auto itr = used.begin();
        if(*itr < v[i]){
            //o2("removed", *itr);
            used.erase(itr);
            used.insert(v[i]);
            //o2("added",v[i]);
        }    
        free++;
        
    }
    ll ans = 0;
    for(auto itr = used.begin(); itr!=used.end(); itr++){
       // o2("summing",*itr);
        ans+=*itr;
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