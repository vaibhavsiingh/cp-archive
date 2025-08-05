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
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);
    ll count0=0; 
    for(ll i = 0; i < n; i++) {
        count0 += (a[i]==0);
    }
    ll gone =0;
    vector<pll> steps;
    for(ll i = 0; i < n-1 && count0 >0; i++) {
        if(a[i]==0){
            steps.pb({i+1-gone,i+2-gone});
            if(a[i+1]==0) count0--;
            count0--;
            i++;
            gone++;
        }
    }
    if(count0>0 && a[n-1]==0){
        steps.pb({n-gone-1,n-gone});
        gone++;
    }
    steps.pb({1,n-gone});
    o1(steps.size());
    for(auto [x,y]:steps){
        o2(x,y);
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