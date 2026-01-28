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
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    vll ans(n+1,0);
    ll mx;
    if(n%2){
        mx=(n-1)*((n-1)/2+1);
    }
    else mx = (n*n)/2;
    if(k>mx || k<0 || k%2==1){
        o1("No");
        return;
    }
    
    for(ll i=1; i<=n/2 && k!=0; i++){
        ll mxPos = 2*(n+1-2*i);
        if(k>=mxPos){
            k-=mxPos;
            ans[i]=n+1-i;
            ans[n+1-i]=i;
        }
        else{
            ll ind = n-i+1-k/2;
            ans[ind]=n-i+1;
            ans[n+1-i]=ind;
            break;
        }
    }
    o1("YES");
    for(ll i = 1; i <= n; i++) {
        if(ans[i]==0){
            cout << i << ' ';
        }
        else cout << ans[i] << ' ';
    }
    cout << "\n";
    
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
}