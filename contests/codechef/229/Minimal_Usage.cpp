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
    ll n,k,s,m;
    i2(n,k);
    i2(s,m);

    if(m == 1){
        for(ll t=0; t<=k; t++){
            ll mn = (k-t)*2;
            ll need = s - t;
            if(need >= mn){
                o1(t);
                return;
            }
        }        
    }
    else if(m == n){
        for(ll t=0; t<=k; t++){
            ll mx = (k-t)*(n-1);
            ll need = s - t*n;
            if(need <= mx){
                o1(t);
                return;
            }
        }
    }
    else{
        for(ll t=0; t<=k; t++){
            ll K = k, S = s;
            ll mn = t+(m+1)*(K-t);
            ll mx = t*(m-1)+(K-t)*n;
            if(mn<=S && S<=mx){
                o1(0);
                return;
            }                        
        }
        for(ll t=0; t<=k; t++){
            ll K = k-1, S = s-m;
            ll mn = t+(m+1)*(K-t);
            ll mx = t*(m-1)+(K-t)*n;
            if(mn<=S && S<=mx){
                o1(1);
                return;
            }                        
        }     
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