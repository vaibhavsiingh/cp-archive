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

    const ll MOD = 1000000007;

    void sol(){
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }
        
        ll total_or = 0;
        for (ll x : a){
            total_or |= x;
        }
        
        ll bits = total_or ? floor(log2(total_or)) + 1 : 1;
        ll max_mask = (1LL << bits) - 1;

        vector<vector<ll>> dp(k+1, vector<ll>(max_mask+1, 0));
        dp[0][0] = 1;

        for (ll x : a) {
            for (ll t = k - 1; t >= 0; t--) {
                for (ll mask = 0; mask <= max_mask; mask++) {
                    if (dp[t][mask] != 0) {
                        ll new_mask = mask | x;
                        dp[t+1][new_mask] = (dp[t+1][new_mask] + dp[t][mask]) % MOD;
                    }
                }
            }
        }
        

        for (ll i = 0; i < q; i++){
            ll x;
            cin >> x;
            
            if (x > max_mask) {
                cout << 0 << "\n";
            } else {
                cout << dp[k][x] << "\n";
            }
        }
    }

    int main(){
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sol();
    }
