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
    int a,b;
    cin >> a >> b;
    vll x,y;
    while(a!=0){
        x.pb(a%10);
        a/=10;
        y.pb(b%10);
        b/=10;
    }
    reverse(all(x));
    reverse(all(y));
    int ans=0;
    int n = x.size();
    int i=0;

    while(i<n && x[i]==y[i]) i++, ans+=2;
    if(i==n){
        o1(ans);
        return;
    }
    if(y[i]-x[i]>=2) {
        o1(ans); 
        return; 
    }
    int ans1 = ans+1;
    int idx = i+1;
    while(idx<n && x[idx]==9) {
        if(y[idx]==9) ans1++;
        idx++, ans1++;
    }
    if(idx<n && (x[idx]==8 && y[idx]==9))ans1++;

    int ans2 = ans+1;
    idx = i+1;
    while(idx<n && y[idx]==0) {
        if(x[idx]==0) ans2++;
        idx++, ans2++;
    }
    if(idx<n && (y[idx]==1 && x[idx]==0))ans2++;

    o1(min(ans1,ans2));

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