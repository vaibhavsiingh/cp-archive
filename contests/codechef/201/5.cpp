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

// sum 1..t mod
inline ll sumFirst(ll t){
    if(t <= 0) return 0;
    t %= MOD;
    ll res = modMul(t, (t + 1) % MOD);
    ll inv2 = (MOD + 1) / 2;
    return modMul(res, inv2);
}
// sum range L..R mod
inline ll sumRange(ll L, ll R){
    if(R < L) return 0;
    // (L+R)*(R-L+1)/2
    ll cnt = (R - L + 1) % MOD;
    ll sumLR = ( (L % MOD) + (R % MOD) ) % MOD;
    ll res = modMul(sumLR, cnt);
    ll inv2 = (MOD + 1) / 2;
    return modMul(res, inv2);
}

// cache Gk per (n,k)
static unordered_map<unsigned long long, ll> Gcache;

void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a, n);

    vector<int> vis(n, 0);
    unordered_map<int,int> cnt; cnt.reserve(16);
    for(ll i=0;i<n;i++){
        if(!vis[i]){
            int len=0;
            ll x=i;
            while(!vis[x]){
                vis[x]=1;
                len++;
                x = a[x]-1;
            }
            if(len>1) cnt[len]++;
        }
    }

    ll ans = 0;
    if(Gcache.bucket_count() < 1024) Gcache.reserve(1024);

    for(auto &pr : cnt){
        int k = pr.first;
        int multiplicity = pr.second;

        unsigned long long key = ( (unsigned long long)n << 32 ) | (unsigned long long)k;
        auto it = Gcache.find(key);
        ll Gk = 0;
        if(it != Gcache.end()){
            Gk = it->second;
        } else {
            // compute Gk using grouping of A where t = floor(k*A/(k-1)) is constant
            ll km1 = k - 1;
            ll A = 1;
            ll localG = 0;
            ll kmod = k % MOD;
            while(A <= n){
                // compute t0 = floor(k*A / (k-1))
                __int128 num = (__int128)k * A;
                ll t0 = (ll)(num / km1);
                if(t0 >= n){
                    // for all remaining A, t = n
                    ll L = A, R = n;
                    ll c = (R - L + 1);
                    // part1 per A = (k-1) * sumFirst(n)
                    ll part1_perA = modMul(km1 % MOD, sumFirst(n));
                    ll totalPart1 = modMul(part1_perA, c % MOD);
                    // part2 = k * (n - n) * sumA = 0
                    // but in original formula t=min(n,t0), so when t==n part2 is k*(n-n)*sumA=0
                    localG = modAdd(localG, totalPart1);
                    break;
                } else {
                    ll t = t0;
                    // compute max A' such that floor(k*A'/km1) == t
                    // condition: k*A' / km1 < t+1  => A' <= floor(((t+1)*km1 -1)/k)
                    __int128 up = (__int128)(t + 1) * km1 - 1;
                    ll Amax = (ll)( up / k );
                    if(Amax > n) Amax = n;
                    if(Amax < A) Amax = A; // safety

                    ll L = A, R = Amax;
                    ll c = (R - L + 1); // count
                    // part1 per A = (k-1) * sumFirst(t)
                    ll part1_perA = modMul(km1 % MOD, sumFirst(t));
                    ll totalPart1 = modMul(part1_perA, c % MOD);

                    // part2 = k * (n - t) * sum_{A=L..R} A
                    ll sumA = sumRange(L, R);
                    ll nt_mod = ((n - t) % MOD + MOD) % MOD;
                    ll part2 = modMul( modMul(kmod, nt_mod), sumA );

                    localG = modAdd(localG, modAdd(totalPart1, part2));

                    A = Amax + 1;
                }
            } // end while

            Gk = localG;
            Gcache.emplace(key, Gk);
        }

        ll add = modMul(Gk, multiplicity % MOD);
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
