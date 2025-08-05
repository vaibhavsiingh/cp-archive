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
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

static vector<ll> fact = {1};
static vector<ll> invfact = {1};
static ll computed_max_a = 0;

ll expo(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp = expo(a,b/2);
    ll ans = (temp*temp)%MOD;
    if(b%2==0){
        return ans;
    }
    else{
        return (ans*a)%MOD;
    }
}

ll nCr(ll n, ll r) {
    if (n < r) return 0;
    ll num = 1;
    for (ll i = 0; i < r; i++) {
        ll term = (n - i) % MOD;
        if (term < 0) term += MOD;
        num = (num * term) % MOD;
    }
    num = (num * invfact[r]) % MOD;
    return num;
}

void sol(){
    ll a, b, k;
    cin >> a >> b >> k;

    if (a > computed_max_a) {        
        fact.resize(a+1);
        for (ll i = computed_max_a + 1; i <= a; i++) {
            fact[i] = fact[i-1] * i % MOD;
        }
        
        invfact.resize(a+1);
        invfact[a] = expo(fact[a], MOD-2);
        for (ll i = a; i > computed_max_a; i--) {
            invfact[i-1] = invfact[i] * i % MOD;
        }
        computed_max_a = a;
    }

    ll tmp = (ll)k * (a - 1) + 1;
    ll n_mod = (ll)(tmp % MOD);
    
    ll Cna = nCr(n_mod, a);
    
    ll m_mod = (( (b - 1) % MOD + MOD) % MOD) * (k % MOD) % MOD;
    m_mod = (m_mod * Cna) % MOD;
    m_mod = (m_mod + 1) % MOD;

    o2(n_mod, m_mod);
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
