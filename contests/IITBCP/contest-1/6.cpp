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
    ll n, L, R;
    cin >> n >> L >> R;

    ll skipped = 0;
    bool first = true;

    //
    ll i = 1;
    while(i < n){
        ll block_len = 2*(n - i);
        if (skipped + block_len < L){
            skipped += block_len;
            ++i;
        } else {
            break;
        }
    }

    
    if (i < n){
        ll block_len   = 2*(n - i);
        ll start_k     = max<ll>(1, L - skipped);
        
        ll evens_skip  = (start_k - 1) / 2;
        ll j           = i + 1 + evens_skip;

        for (ll k = start_k; k <= block_len; ++k){
            ll pos_abs = skipped + k;
            if (pos_abs > R) break;

            ll val;
            if (k & 1){
                val = i;
            } else {
                val = j;
                ++j;
            }

            if (pos_abs >= L){
                if (!first) cout << ' ';
                cout << val;
                first = false;
            }
        }
        skipped += block_len;
    }

    
    for (++i; i < n && skipped < R; ++i){
        ll block_len = 2*(n - i);
        if (skipped + block_len < L){
            skipped += block_len;
            continue;
        }
        ll j = i + 1;
        rep0(k, block_len){
            ll idx = k + 1;
            ll pos_abs = skipped + idx;
            if (pos_abs > R) break;

            if (pos_abs >= L){
                ll val = (idx & 1 ? i : j);
                if (!(idx & 1)) ++j;
                if (!first) cout << ' ';
                cout << val;
                first = false;
            } else {
                if (!(idx & 1)) ++j;
            }
        }
        skipped += block_len;
    }

    
    ll total_len = n*(n - 1) + 1;
    if (L <= total_len && total_len <= R){
        if (!first) cout << ' ';
        cout << 1;
    }

    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t; 
    cin >> t;
    rep0(tc, t) sol();
    return 0;
}
