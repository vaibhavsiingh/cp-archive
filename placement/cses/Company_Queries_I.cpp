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
    ll n,q;
    cin >> n >> q;

    vector<vll> dp(n+1, vll(20));
    for(ll i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        dp[i][0] = x;
    }

    for(ll i=1; i<20; i++){
        for(ll nd=1; nd<=n; nd++){
            dp[nd][i] = dp[dp[nd][i-1]][i-1];
        }
    }

    while(q--){
        ll nd, l;
        cin >> nd >> l;

        ll pow=(1<<19);
        ll idx = 19;        

        while(l>0){
            if(pow > l) pow  =  pow >> 1, idx--;
            else{
                l -= pow;
                nd = dp[nd][idx];
            }
        }
        if(nd==0) o1(-1);
        else o1(nd);
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}