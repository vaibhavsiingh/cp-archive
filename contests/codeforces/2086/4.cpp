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

ll num_ways(vll c, ll sm){
    vll dp(sm+1);
    dp[0] = 1;
    for (int x : c) {
        for (int j = sm; j >= x; j--) {
            dp[j] = (dp[j] + dp[j - x]) % MOD;
        }
    }
    return dp[sm];
}


void sol(){
    vll c;
    ll sm =0;    
    
    for(ll i = 0; i < 26; i++) {
        ll x;
        cin >> x;
        if(x!=0) {
            c.push_back(x);
            sm+=x;
        }
    }
    ll r = (sm+1)/2;
    ll e = (sm)/2;

    vll fact(sm+1);
    
    fact[0] = 1;
    for(ll i = 1; i <= sm; i++) {
        fact[i] = (fact[i-1]*i)%MOD;
    }
    ll denom = 1;
    for(auto x:c){
        ll inv_fact = expo(fact[x],MOD-2);
        denom = (denom*inv_fact)%MOD;
    }

    ll ways = num_ways(c,r);

    ll res = (ways*fact[r])%MOD;
    res = (res*fact[e])%MOD;
    res = (res*denom)%MOD;
    o1(res);
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