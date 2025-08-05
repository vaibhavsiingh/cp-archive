

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
    vll bin;
    ll msb=0;
    for(ll i=63; i>=0; i--){
        if(msb==0 && n>>i&1) msb=i;
        if(msb==0) continue;
        if(n>>i&1)bin.pb(1);
        else bin.pb(0);
    }
    vll ones;
    vll ans;
    for(ll i = 0; i < bin.size(); i++) {
        if(bin[i]==1) ones.pb(i);
    }
    for(ll i = 0; i < ones.size(); i++) {
        ll out=0;
        for(ll j=0; j<bin.size(); j++ ){
            if(j==ones[i]) continue;
            ll temp=1;
            out+=bin[j]*(temp<<(bin.size()-1-j));
        }
        if(out==0) continue;
        else ans.pb(out);
    }
    ans.pb(n);
    o1(ans.size());
    oArray(ans,ans.size());

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