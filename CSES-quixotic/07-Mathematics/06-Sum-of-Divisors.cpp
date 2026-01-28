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
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;
const ll MAX_N = 1e12;
const ll GOOD_N = 1e6;


void sol(){
    ll n;
    cin >> n;
    ll sm = 0;
    ll check = 0;
    for(ll num=1; num<=GOOD_N; num++){
        ll count = n/num;
        sm = (sm+ (count*num)%MOD)%MOD;
        if((GOOD_N+1)<=count){
            ll count_bad_factors = (count-GOOD_N);                            
         //   o2(count,count_bad_factors);
            ll inv2 = (MOD + 1) / 2;   // valid if MOD is prime
            ll to_sm = count_bad_factors % MOD;
            to_sm = (to_sm * ((count + GOOD_N + 1) % MOD)) % MOD;
            to_sm = (to_sm * inv2) % MOD;
            if(to_sm<0) o1("WHAT");
            sm = (sm+to_sm)%MOD;
            check = 1;
        }
                
    }
    o1(sm);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}