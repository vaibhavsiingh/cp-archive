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

ll modex(ll a, ll b, ll m){
    if(b==0) return 1;
    ll term = modex(a,b/2,m);
    if(b%2) return (((term*term)%m)*a)%m;
    else return (term*term)%m;
}

ll modinv(ll a, ll m){
    return modex(a,m-2,m);
}

void sol(){
    ll n;
    cin >> n;
    vll primes(n);
    vll num_p(n);
    for(ll i = 0; i < n; i++) {
        i2(primes[i], num_p[i]);    
    }
    ll nd = 1;
    for(ll i=0; i<n; i++) nd = (nd*(num_p[i]+1))%MOD;

    ll sd = 1;
    for(ll i=0; i<n; i++){
        ll term = (((modex(primes[i], num_p[i]+1, MOD)-1+MOD)%MOD)*modinv(primes[i]-1,MOD))%MOD;
        sd = (sd*term)%MOD;
    }

    ll db2 = 1;
    bool divided = false;
    for(ll i=0; i<n; i++){
        ll mul = num_p[i]+1;
        if(!divided && mul%2==0){
            divided = true;
            mul /= 2;
        }
        db2 = (db2*mul)%(MOD-1);
    }

    ll N = 1;
    for(ll i=0; i<n; i++){
        ll mul;
        if(divided) mul = modex(primes[i], num_p[i], MOD);
        else mul = modex(primes[i], num_p[i]/2, MOD);
        N = (N*mul)%MOD;
    
    }
  //  o1(db2);
    ll md = modex(N, db2, MOD);
    cout << nd << ' ' << sd << ' ' << md << endl;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    
}