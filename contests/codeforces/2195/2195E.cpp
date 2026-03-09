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

vll dp, ans;

void recurse(ll nd, vector<vll>& chd){
    if(chd[nd][0]==-1) {
        dp[nd] = 0;
        return;
    }
    recurse(chd[nd][0], chd);
    recurse(chd[nd][1], chd);
    dp[nd] = (4+dp[chd[nd][0]]+dp[chd[nd][1]])%MOD;
}

void rec(ll nd, vector<vll>& chd, ll par){
    ans[nd] = (dp[nd]+1+ans[par])%MOD;
    if(chd[nd][0]!=-1) {
        rec(chd[nd][0], chd, nd);
        rec(chd[nd][1], chd, nd);
    }
}

void sol(){
    ll n;
    cin >> n;
    vector<vll> chd(n+1, vll(2,-1));
    vll par(n+1);
    for(ll i = 0; i < n; i++) {
        ll x,y;
        i2(x,y);
        if(x==0) continue;
        chd[i+1][0]=x;
        chd[i+1][1]=y;
        par[x] = i+1;
        par[y] = i+1;        
    }
    dp.resize(n+1,-1);
    recurse(1, chd);
    ans.resize(n+1,0);
    //ans[1] = dp[1]+1;
    rec(1, chd, 0);
    for(ll i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    o1("");

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
    return 0;
}