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
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);

    ll sm = accumulate(all(a), 0ll);

    vll dp(sm+1,0);
    dp[0] = 1;
    for(ll i=0; i<n; i++){
        for(ll j=sm; j>0; j--){
            if(j-a[i]>=0){
                dp[j] =  dp[j] | dp[j-a[i]];
            }
        }
    }
    vll ans;
    for(ll x=1; x<=sm; x++){
        if(dp[x])   {
            ans.pb(x);
        }
    }
    o1(ans.size());
    oArray(ans, ans.size());

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}