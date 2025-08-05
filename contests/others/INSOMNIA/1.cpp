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

ll countSetBits(ll n) {
    ll count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void sol(){
    ll x, y;
    cin >> x >> y;
    
    if(y > x){
        o1(-1);
        return;
    }
    
    ll ans = y;
    for (ll i = 0; i < 63; i++){
        ll mask = 1LL << i;
        if((ans | mask) <= x)
            ans |= mask;
    }
    int r = countSetBits(ans);    
    if(y==0){
        if(r <= 1)
        o1(1);
        else o1((1ll << r)); 
    }
    else{
        if(r==1)
            o1(2);
        else
            o1(((1LL << r) - 1));
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
