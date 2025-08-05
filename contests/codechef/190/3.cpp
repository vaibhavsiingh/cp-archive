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
    ll n,x;
    i2(n,x);
    vll a(n), b(n);
    iArray(a,n);
    iArray(b,n);
    vll mx_a(n);
    if(n==1){
        if(x>=b[0]){
            o1(1);
        }
        else o1(0);
        return;
    }
    mx_a[n-2] = a[n-1];
    for(int i=n-3; i>=0; i--){
        mx_a[i] = max(a[i+1],mx_a[i+1]);
    }
   // oArray(mx_a,n);
    if(mx_a[0]>x){
        o1(0);
        return;
    }
    int ans=0;
    for(int i=0; i<n; i++){
        if(x>=b[i] && x-1>=mx_a[i]){
            ans++;
            x--;
        }
    }
    o1(ans);
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