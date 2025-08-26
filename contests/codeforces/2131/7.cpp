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

const ll MOD = 1000000007;
const ll INF = 1e18;

vector<ll> dp(32);

ll fun(ll ele, ll k){
    if(k==0) return 1;
    k--;
    ll ret = ele;
    for(ll i=1; i<ele; i++){
        if(i<=31 &&  (1ll<<(i-1))<=k){
            k-=(1ll<<(i-1));
            ret = (ret*dp[i])%MOD;
        }
        else{
            ret = (ret*fun(i,k))%MOD;
            break;
        }
    }
    return ret;
}


void sol(){
    ll n,k;
    cin >> n >> k;
    vll a(n);
    iArray(a,n);
    sort(a.begin(),a.end());
    ll ans = 1;
    for(int s: a){
        if(s<=31 && (1ll<<(s-1))<=k){
            k-= (1ll<<(s-1));
            ans = (ans*dp[s])%MOD;            
        }
        else{
            ans = (ans*fun(s,k))%MOD;
            break;
        }
    }
    o1(ans);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;

    dp[1] = 1;
    for(int i=2; i<32; i++){
        dp[i] = i;
        for(int j=1; j<i; j++){
            dp[i] = (dp[i]*dp[j])%MOD;
        }
    }

    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}