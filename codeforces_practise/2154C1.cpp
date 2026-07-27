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

const int MAXA = 2e5 + 5;

int spf[MAXA];

void sieve() {
    for (int i = 0; i < MAXA; i++) spf[i] = i;

    for (int i = 2; i * i < MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXA; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


void sol(){
    int n;
    cin >> n;

    vll a(n), b(n);

    iArray(a,n);
    iArray(b, n);

    unordered_set<int> seen;

    for(auto x: a){
        while(x > 1){
            int p = spf[x];
            if(seen.count(p)){
                o1(0);
                return; 
            }
            seen.insert(p);
            while(x % p == 0) {
                x /= p;
            }
        }        
    }

    vector<pair<int,int>> a_mod;
    for(int i=0; i<n; i++){
        a_mod.push_back({a[i],0});
        a_mod.push_back({a[i]+1,1});
    }

    set<pair<int,int>> seen_mod;
    for(auto [x, type]: a_mod){
        vector<int> primes;
        while(x > 1){
            int p = spf[x];            
            primes.push_back(p);
            while(x % p == 0) {
                x /= p;
            }
        }        
        int check_type = (type == 0) ? 1 : 0;
        for(auto p:primes){
            seen_mod.insert({p, type});
            if(seen_mod.count({p, check_type})){
                o1(1);
                return;
            }
        }
    }
    o1(2);
    return;




}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;

    sieve();
    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}