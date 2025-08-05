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
const ll INF = 1e10;

void sol(){
    ll n,x,y;
    cin >> n;
    i2(x,y);
    vll a(n);
    iArray(a,n);

    vll dp(x+1,INF);
    dp[x] = 0;
    
    for(ll j=x; j>=0; j--){
        for(int i=0; i<n; i++){
            if(dp[j]==INF) continue;
            ll new_x = j%a[i];
            dp[new_x] = min(dp[new_x],max((ll)i,dp[j]));
        }
    }

    vll ans;
    ll mn = INF;
    for(ll i = 0; i < n; i++) {
        mn = min(mn,a[i]);
        if(mn>y && dp[y]<=i) ans.pb(i+1);
    }
    o1(ans.size());
    oArray(ans,ans.size());
    
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