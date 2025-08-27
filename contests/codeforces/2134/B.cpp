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

ll gcd_(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll modpow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

ll modInverse(ll m, ll p) {
    return modpow(m, p - 2, p);  
}

ll minAdditions(ll n, ll m, ll p) {
    n %= p;
    m %= p;

    if (n == 0) return 0;                  
    if (m == 0) return -1;                 

    long long inv = modInverse(m, p);      
    long long k = ((p - n) * inv) % p;     
    if (k < 0) k += p; 
    return k;
}

void sol(){
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);
    if(n==1){
        if(a[0]==1) o1(1+k);
        else o1(a[0]);
        return;
    }
    ll gcd = a[0];
    for(ll i = 1; i < n; i++) {
        gcd = gcd_(a[i],gcd);
    }
    if(gcd>1){
        oArray(a,n);
    }
    else{
        if(k%2==1){
            for(ll i = 0; i < n; i++) {
                if(a[i]%2==1){
                    a[i]+=k;
                }
            }
        }
        else{
            vll primes = {2,3,5,7,11,13,17,19,23,29,31,37};
            ll smpi = 0;
            while(k%primes[smpi]==0)smpi++;
            for(ll i = 0; i < n; i++) {
                if(a[i]==1) a[i]+=k;
                a[i] += k*minAdditions(a[i],k,primes[smpi]);
            }            
                        
        }
        oArray(a,n);
    }
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