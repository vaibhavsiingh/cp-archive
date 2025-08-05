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
#define all(x) x.begin(), x.end()

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    vector<pll> v,nv;
    vector<vll> m(2*n+1,vll(2*n+1));
    for(ll i = 0; i < n; i++) {
        ll x,y;
        i2(x,y);
        v.pb({x-y,i});
        v.pb({x+y,i});
    }
    sort(all(v));
    vll temp(n,-1);
    for(ll i = 0; i < 2*n; i++) {
        if(temp[v[i].ss]!=-1){
            nv.pb({temp[v[i].ss],i});
        }
        else temp[v[i].ss] = v[i].ss;
    }
    vector<vll> dp(2*n+1,vll(2*n+1));
    sort(all(nv));
    
    for(auto& [l,r]:nv){
        m[l][r] = 1;
        dp[l][r]++;
    }
    for(ll len = 1; len < 2*n; len++) {
        ll p=n-1;
        for(ll l=2*n-len-1; l>=0; l--){
            ll r = l+len;
            while(nv[p].ff > l) p--;
            dp[l][r] = dp[l+1][r];
            while(nv[p].ff==l){
                dp[l][r] = max(dp[l][r],dp[l][nv[p].ss]+dp[nv[p].ss][r]);
            }
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}