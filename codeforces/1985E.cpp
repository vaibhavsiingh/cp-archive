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
    ll x,y,z,k;
    cin >> x >> y >> z >> k;
    ll end = cbrt(x);
    ll mx = 0;
    for(ll i = 1; i <= x; i++) {
        //o1("1st");
        //o2(k,i);
        if(k%i==0){
            for(ll j=1; j<=y; j++){
                //o2("2nd",j);
                if(k%(i*j)==0){
                    ll l = k/(i*j);
                    //o2("3rd",l);
                    if(l<=z){
                        mx = max(mx,(x-i+1)*(y-j+1)*(z-l+1));
                    }
                }
            }
        }
    }
    o1(mx);
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