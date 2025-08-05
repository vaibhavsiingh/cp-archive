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
    i2(n,m) ;
    vll a(n),b(m);
    iArray(a, n);
    iArray(b, m);
    auto min_pos = min_element(b.begin(), b.end()) - b.begin();
    rotate(b.begin(), b.begin() + min_pos, b.end());
    if(m==1){
        for(ll i = 0; i < n; i++) {
            if(a[i]>b[0]){
                a[i] = b[0];
            }
        }
        oArray(a,n);
        return;
    }
    for(ll i = 0; i < n-m+1; i++) {
        if(a[i]>b[0]){
            for(ll j=i; j+m-1<n; j++){
                a[j] = b[0];
            }
            for(ll j=1; j<m; j++){
                a[j+n-m] = b[j];
            }
            oArray(a,n);
            return;
        }
        if(a[i]<b[0]) continue;
        if(i!=n-m)continue;
        bool smaller = false;
        for(ll j=0; j<m; j++){
            if(a[i+j] == b[j]) continue;
            if(a[i+j]>b[j]) {
                smaller=true;
                break;
            }
            break;
        }
        if(smaller){
            for(ll j=0; j<m; j++){
                a[i+j] = b[j];
            }
        }
    }
    oArray(a,n);
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