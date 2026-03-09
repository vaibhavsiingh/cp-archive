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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 998244353;
const ll INF = 1e18;
const ll MAXN = 50;

vector<ll> fac;

ll expo(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp = expo(a,b/2);
    ll ans = (temp*temp)%MOD;
    if(b%2==0){
        return ans;
    }
    else{
        return (ans*a)%MOD;
    }
}

void sol(){
    ll n;
    cin >> n;
    vll a(n+1);
    iArray(a,n+1);
    ll mx = *max_element(++a.begin(), a.end());

    ll mn_cost = 0;
    ll mx_ele = 0;
    for(int i=1; i<=n; i++){
        if(a[i]==mx){
            mx_ele++; continue;
        }
        mn_cost += mx-1 - a[i];
    }    
    if(a[0]<mn_cost){
        o1(0);
        return;
    }
    a[0] -= mn_cost;
    if(a[0]> n-mx_ele){
        mx_ele = 0;
        a[0] -= mx_ele;
    }
    a[0] = a[0]%n;
    // mx_ele += a[0];
    
    ll x = (fac[n-mx_ele]*fac[mx_ele+a[0]])%MOD;    
    ll y = expo(fac[a[0]],MOD-2);
    ll z = (x*y)%MOD;
    o1(z);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    fac.resize(2*MAXN+1);
    fac[0] = 1;
    for(ll i=1; i<=2*MAXN; i++){
        fac[i] = (fac[i-1]*i)%MOD;
    }
    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}