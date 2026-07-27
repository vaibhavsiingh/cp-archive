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
    ll n,k;
    i2(n,k);

    vll a(n);
    iArray(a,n);

    for(ll i=0; i<n; i++){
        if(a[i]==1){
            ll j=i+1;
            for(; j<=i+k && j < n; j++){
                if(a[j]==1){
                    o1("No");
                    return;
                }            
            }
            i=j;
        }
    }
    for(ll i=0; i<n; i++){
        if(a[i]==0){
            bool all_zero = true;
            for(ll j=max(0ll,i-k); j<=min(i+k,n-1); j++){
                if(a[j]==1){
                    all_zero = false;
                    break;
                }                
            }
            if(all_zero){
                o1("No");
                return;
            }
        }
    }
    o1("Yes");
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