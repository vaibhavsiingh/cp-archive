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

const ll INF = LLONG_MAX;

ll solve_line(int n, vll &cost, vector<array<bool,3>> &allowed) {

    ll dp0 = 0, dp1 = cost[0];
    rep(i, 0, n-1) {
        ll ndp0 = INF, ndp1 = INF;
        rep(prev, 0, 2) {
            ll dp_prev = prev ? dp1 : dp0;
            if (dp_prev == INF) continue;
            rep(curr, 0, 2) {
                int d = curr - prev + 1;        
                if (!allowed[i][d]) continue;
                ll c = dp_prev + (curr ? cost[i+1] : 0);
                if (curr) ndp1 = min(ndp1, c);
                else      ndp0 = min(ndp0, c);
            }
        }
        dp0 = ndp0;
        dp1 = ndp1;
    }
    return min(dp0, dp1);
}

void sol(){
    int n;
    cin >> n;
    vector<vll> h(n, vll(n));
    rep0(i, n) rep0(j, n) cin >> h[i][j];

    vll a(n), b(n);
    iArray(a, n);
    iArray(b, n);

    vector<array<bool,3>> allowed_x(n-1, {true, true, true});
    rep(i, 0, n-1) {
        rep0(j, n) {
            ll diff = h[i][j] - h[i+1][j];
            if (abs(diff) <= 1) allowed_x[i][diff + 1] = false;
        }
    }

    vector<array<bool,3>> allowed_y(n-1, {true, true, true});
    rep(j, 0, n-1) {
        rep0(i, n) {
            ll diff = h[i][j] - h[i][j+1];
            if (abs(diff) <= 1) allowed_y[j][diff + 1] = false;
        }
    }

    ll best_rows = solve_line(n, a, allowed_x);
    ll best_cols = solve_line(n, b, allowed_y);

    ll ans = (best_rows < INF && best_cols < INF)
             ? best_rows + best_cols
             : -1;
    o1(ans);
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