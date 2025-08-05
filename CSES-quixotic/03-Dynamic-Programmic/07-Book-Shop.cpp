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

const ll MOD = 1000000007;


void sol(){
    ll n,x;
    i2(n,x);
    vector<ll> price(n), npages(n);
    iArray(price,n);
    iArray(npages,n);
    vector<ll> dp(x+1);
    for(int i=price[0]; i<=x; i++) dp[i]=npages[0];
    for(ll i = 1; i < n; i++) {
        for(int j=x; j>0; j--){
            if(j>=price[i]){
                dp[j]=max(dp[j],dp[j-price[i]]+npages[i]);
            }
            else{
                dp[j]=dp[j];
            }
          //  cout << i << ' ' << j << ' ' << dp[i][j] << "\n";
        }
    }
    o1(dp[x]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}