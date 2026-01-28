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
    ll n;
    cin >> n;
    vll a(n), c(n);
    iArray(a,n);
    iArray(c,n);

    vll dp1(n, INF), dp2(n, INF);
    dp1[0] = 0;
    dp2[n-1] = 0;
    for(ll i=1; i<n; i++){
        ll cost = 0;        
        for(ll j=i-1; j>=0; j--){
            if(a[j]>a[i]) cost += c[j];
            else{
                dp1[i] = min(cost+dp1[j], dp1[i]);
                cost += c[j];
            }
        }
        dp1[i] = min(dp1[i],cost);
    }
    for(ll i=n-2; i>=0; i--){
        ll cost = 0;        
        for(ll j=i+1; j<n; j++){
            if(a[j]<a[i]) cost += c[j];
            else{
                dp2[i] = min(cost+dp2[j], dp2[i]);
                cost += c[j];
            }
        }
        dp2[i] = min(dp2[i],cost);
    }
    ll mn = INF;
    for(ll i = 0; i < n; i++) {
        mn = min(mn, dp1[i]+dp2[i]);
    }
    o1(mn);
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