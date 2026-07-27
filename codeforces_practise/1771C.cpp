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

ll underrotA = 32000;

vector<ll> primes;

void collect_primes(){
    vector<ll> sieve(underrotA,1);    
    for(ll prime = 2; prime < underrotA; prime++){
        if(sieve[prime] != 1) continue;
        primes.push_back(prime);
        for(ll factor = 2*prime; factor < underrotA; factor += prime){
            if(sieve[factor] == 1){
                sieve[factor] = 0;
            }
        }
    }
}

void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);

    unordered_map<ll,ll> factors;
    ll P = primes.size();
    for(ll num: a){
        for(ll i=0;i<P &&  primes[i] < num; i++)       {
            ll p = primes[i];
            if(num % p != 0) continue;
            factors[p]++;
            if(factors[p] > 1){
                o1("YES");
                return;
            }
            while(num > 1 && num % p == 0){
                num /= p;
            }            
        }
        if(num > 1){
            factors[num]++;
            if(factors[num] > 1){
                o1("YES");
                return;
            }
        }
    }
    o1("NO");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    collect_primes();
    for(ll i = 0; i < t; i++) {
        sol();
    }
    
    return 0;
}