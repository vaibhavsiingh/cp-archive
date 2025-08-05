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

const ll MOD = 998244353;

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

ll func(ll k){
    ll ans = 0;
    ll pow4 =-1;
    for(int i=0; i<k; i++){
        ans -= pow4;
        ans %= MOD;
        pow4 *= -4;
        pow4 %= MOD;
    }
    return ans;
}

void sol(){
    ll t;
    cin >> t;
    ll max_found = 0;
    vll ans(1e3+1);
    vll pow2(1e3+1);
    vll x(1e3+1), y(1e3+1);
    pow2[1] = 1;
   while(t--){
    ll n;
    cin >> n;
    if(n<=max_found){
        o1((x[n]-y[n])%MOD);
        continue;
    }
    for(ll i=max_found+1; i<=n; i++){
        if(i!=1) pow2[i] = (pow2[i-1]<<1)%MOD;
        if(i%4==0 || i%4==3){
            ans[i] = (ans[i-1]+pow2[i])%MOD;
            x[i] = ans[i];
            y[i] = y[i-1];
        }
        else{
            ans[i] = (ans[i-1]-pow2[i])%MOD;
            y[i] = ans[i];
            x[i] = x[i-1];
        }
    }
    o1((x[n]-y[n])%MOD);
    max_found=n;
   }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}