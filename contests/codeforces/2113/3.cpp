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
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> grid(n);
    rep0(i, n){
        cin >> grid[i];
    }

    vector<vector<ll>> P(n+1, vector<ll>(m+1, 0));
    ll total_gold = 0;
    rep0(i, n){
        rep0(j, m){
            bool isGold = (grid[i][j]=='g' || grid[i][j]=='G');
            if(isGold) total_gold++;
            P[i+1][j+1] = P[i][j+1] + P[i+1][j] - P[i][j] + (isGold ? 1 : 0);
        }
    }
    auto sumRect = [&](int r1, int c1, int r2, int c2)->ll{        
        return P[r2+1][c2+1] - P[r1][c2+1] - P[r2+1][c1] + P[r1][c1];
    };
    
    ll min_loss = LLONG_MAX;
    bool found_empty = false;
    rep0(x, n){
        rep0(y, m){
            if(grid[x][y] != '.') continue;
            found_empty = true;
            ll loss = 0;
            if(k > 0){
                int dx = k - 1;
                int r1 = x - dx;
                int c1 = y - dx;
                int r2 = x + dx;
                int c2 = y + dx;
                r1 = max(r1, 0);
                c1 = max(c1, 0);
                r2 = min(r2, n-1);
                c2 = min(c2, m-1);
                if(r1 <= r2 && c1 <= c2){
                    loss = sumRect(r1, c1, r2, c2);
                }
            }
            min_loss = min(min_loss, loss);
        }
    }
    ll ans = 0;
    if(found_empty){
        ans = total_gold - min_loss;
    } else {
        ans = 0;
    }
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    rep0(i, t){
        sol();
    }
    return 0;
}
