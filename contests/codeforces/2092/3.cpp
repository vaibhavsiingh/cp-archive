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
    vll dp(n);
    dp[0] = a[0];
    bool was_odd=false,was_even=false,has_one=false;
    for(int i=0; i<n; i++){
        if(a[i]%2) was_odd = true;
        else was_even = true;
    }
    if(!was_odd || !was_even){
        o1(*max_element(a.begin(),a.end()));
        return;
    }
    ll nodds = 0;
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        if(a[i]%2) nodds++;
        sum +=a[i];
    }
    o1(sum-nodds+1);
   
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