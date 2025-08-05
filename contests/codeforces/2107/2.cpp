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
    vll a(n);
    iArray(a,n);
    ll sm = 0;
    for(ll i = 0; i < n; i++) {
        sm += a[i];
    }
    ll mx = *max_element(a.begin(),a.end());
    ll mn = *min_element(a.begin(),a.end());
    if(mx-mn>k+1){
        o1("Jerry");
        return;
    }
    if(mx-mn==k+1){
        ll num_mx=0;
        for(ll i = 0; i < n; i++) {
            if(a[i]==mx) num_mx++;
        }
        if(num_mx>1){
            o1("Jerry");
            return;
        }
    }
    
    if(sm%2==0){
        o1("Jerry");
    }
    else{
        o1("Tom");
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