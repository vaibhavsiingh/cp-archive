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
    vector<int> bits(31, 0);
    for (int i = 0; i < 31; i++) {
        bits[i] = (x >> i) & 1;
    }
    ll first1 = 30;
    while(bits[first1]==0) first1--;

    bool containsZero = false;
    for(int i=first1; i>=0; i--){
        if(bits[i]==0) {
            containsZero = true;
            break;
        }
    }

    if(containsZero){
        ll cont_one = 0;
        if(bits[0]==0){
            vll ans(n);
          //  o1("1");
            ans[0] = x;
            oArray(ans, n);
            return;
        }
        while(bits[cont_one]==1) cont_one++;
        cont_one--;
        ll mx = (1<<cont_one+1)-1;
        vll ans(n);
        for(int i=0; i<n-1&&i<=mx; i++){
            ans[i] = i;
        }
        ans[n-1] = x;
     //   o1(cont_one);
        oArray(ans,n);
        return;
    }
    vll ans(n);
    ll res = 0;
    for(int i=0; i<x && i<n-1; i++){
        ans[i] = i;
        res|=i;
    }
    
    if( ((res|(n-1))==x) && n-1<=x) ans[n-1] = n-1;
    else ans[n-1] = x;
    //o1("3");
    oArray(ans,n);

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