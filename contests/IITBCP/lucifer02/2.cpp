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

    ll yes = 0, today=0;
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        yes = today;
        today = a[i];
        if(yes==0){
            ans += today/k;
            today %= k;
            continue; 
        }
        ll x = k-yes;        
        if(x>today){
            yes = 0;
            today=0;
            ans++;
        }
        else{
            today -= x;
            yes=0;
            ans++;
            ans += today/k;
            today %= k;
        }
    }
    if(today!=0) ans++;
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}