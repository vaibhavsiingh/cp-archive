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

void sol(){
    ll n, ax,ay,bx,by;
    cin >> n;
    i2(ax,ay)   ;
    i2(bx,by);

    vector<pll> pnts(n);
    for(ll i = 0; i < n; i++) {
        cin >> pnts[i].ff;
    }
    for(ll i = 0; i < n; i++) {
        cin >> pnts[i].ss;
    }
    sort(all(pnts));
    vector<vll> rel_pnts;
    for(ll i = 0; i < n;) {
        ll x = pnts[i].ff;
        ll mn = INF;
        ll mx = -INF;
        while(i<n && pnts[i].ff == x){
            mn = min(mn, pnts[i].ss);
            mx = max(mx, pnts[i].ss);
            i++;
        }
        rel_pnts.push_back({mn,mx});
    }
    ll ndash = rel_pnts.size();
    vector<vll> dp(ndash, vll(2));
    dp[0][0] = abs(rel_pnts[0][0]-ay) + rel_pnts[0][1]-rel_pnts[0][0];
    dp[0][1] = abs(rel_pnts[0][1]-ay) + rel_pnts[0][1]-rel_pnts[0][0];
   // cout << "point: ";
    //o2(rel_pnts[0][0], rel_pnts[0][1]);
  //  o2(dp[0][0], dp[0][1]);                        
    for(ll i=1; i<ndash; i++){
        dp[i][0] = min(dp[i-1][0] + abs(rel_pnts[i][0]-rel_pnts[i-1][1]) + rel_pnts[i][1]-rel_pnts[i][0],
                        dp[i-1][1] + abs(rel_pnts[i][0]-rel_pnts[i-1][0]) + rel_pnts[i][1]-rel_pnts[i][0] );
        dp[i][1] = min(dp[i-1][0] + abs(rel_pnts[i][1]-rel_pnts[i-1][1]) + rel_pnts[i][1]-rel_pnts[i][0],
                        dp[i-1][1] + abs(rel_pnts[i][1]-rel_pnts[i-1][0]) + rel_pnts[i][1]-rel_pnts[i][0] );                        
       // cout << "point: ";
        //o2(rel_pnts[i][0], rel_pnts[i][1]);
        //o2(dp[i][0], dp[i][1]);                        
    }
    o1(bx - ax + min(dp[ndash-1][0] + abs(by - rel_pnts[ndash-1][1]), dp[ndash-1][1] + abs(by - rel_pnts[ndash-1][0])));

    
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