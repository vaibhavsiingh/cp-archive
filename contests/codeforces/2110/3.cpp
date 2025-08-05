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
    vll path(n);
    iArray(path,n);
    vector<pll> obs(n);
    ll x,y;
    for(ll i = 0; i < n; i++) {
        i2(x,y);
        obs[i] = {x,y};
    }
    vector<pll> dp(n+1);

    vll ans=path,pos;
    dp[0] = {0,0};

    for(int i=0; i<n; i++){
        if(path[i]==-1){
            dp[i+1] = {dp[i].ff,dp[i].ss+1};
        }
        else if(path[i]==0) dp[i+1] = dp[i];
        else dp[i+1] = {dp[i].ff+1,dp[i].ss+1};

        if(dp[i+1].ff>obs[i].ss || dp[i+1].ss < obs[i].ff){
            o1(-1);
            return;
        }
        dp[i+1].ff = max(dp[i+1].ff,obs[i].ff);
        dp[i+1].ss = min(dp[i+1].ss,obs[i].ss);
    }

    ll h = dp[n].ff;
    for(int i=n; i>0; i--){
        if(h>=dp[i-1].ff & h<=dp[i-1].ss && (path[i-1]==-1 || path[i-1]==0)){
            ans[i-1]= 0;
        }
        else{
        ans[i-1] = 1;
        h--;
    }
    }
    
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