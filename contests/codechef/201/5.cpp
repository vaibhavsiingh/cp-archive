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

const ll MOD = 998244353;
const ll INF = 1e18;

inline ll modAdd(ll a, ll b){ a += b; if(a >= MOD) a -= MOD; return a; }
inline ll modSub(ll a, ll b){ a -= b; if(a < 0) a += MOD; return a; }
inline ll modMul(ll a, ll b){ return (ll)((__int128)a * b % MOD); }

inline ll sumFirst(ll t){ //
    t %= MOD;
    ll res = modMul(t, (t + 1) % MOD);
    
    ll inv2 = (MOD + 1) / 2;
    return modMul(res, inv2);
}

void sol(){
    ll n;
    cin >> n;
    vll p(n);
    iArray(p, n);

    vll vis(n, 0ll);
    vll cnt(n+1); 
    for (ll i = 0; i < n; i++){
        if (!vis[i]){
            ll len = 0;
            ll x = i;
            while (!vis[x]){
                vis[x] = 1;
                len++;
                x = p[x] - 1;
            }
            
            if (len > 1) cnt[len]++;
        }
    }

    ll ans = 0;
    
    for (ll len=2; len<=n; len++){        
        

        
        ll Gk = 0;
        for (ll A = 1; A <= n; A++){                        
            ll num = ( len * A );
            ll t = ( num / (len - 1) );
            if (t > n) t = n;
            
            ll part1 = modMul( (len-1) % MOD, sumFirst(t) );
            
            ll part2 = modMul( ( (n - t) % MOD + MOD ) % MOD, modMul( len % MOD, A % MOD ) );
            ll cur = modAdd(part1, part2);
            Gk = modAdd(Gk, cur);
        }
        
        ll add = modMul( Gk, cnt[len] % MOD );
        ans = modAdd(ans, add);
    }

    

    o1(ans % MOD);
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
