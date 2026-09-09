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
    vector<vll> children(n+1);

    for(ll i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        dp[i][0] = x;
        children[x].push_back(i);        
    }

    for(ll i=1; i<20; i++){
        for(ll nd=1; nd<=n; nd++){
            dp[nd][i] = dp[dp[nd][i-1]][i-1];
        }
    }

    vll level(n+1,0);

    auto fillLevel = [&](auto&& self, int nd) -> void{
        for(ll nxt: children[nd]){
            level[nxt] = level[nd]+1;
            self(self, nxt);
        }
    };

    fillLevel(fillLevel, 1);

    auto getUnc = [&](int nd, int d){
        for(ll i=0; i<20; i++){
            if(d & (1 << i)){
                nd = dp[nd][i];
            }
        }
        return nd;
    };

    while(q--){
        ll x,y;
        cin >> x >> y;
        if(level[x] > level[y]){
            swap(x,y);
        }
      //  o2(x,y);
        y = getUnc(y, level[y]- level[x]);
    //    o2(x,y);
        if(x==y){
            o1(x);
            continue;
        }

        ll idx = 19;
        while(idx >= 0){
            if(dp[x][idx] != dp[y][idx]){
                x = dp[x][idx];
                y = dp[y][idx];
            }
            idx--;
        }
        o1(dp[x][0]);
        
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}