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
    ll n,m;
    i2(n,m);
    vll a(n);
    iArray(a,n);
    sort(all(a));

    vector<pll> gaps(n-1);
    for(ll i=0; i<n-1; i++){
        gaps[i] = {a[i+1]-a[i],i};
    }
    sort(all(gaps));
    
    vector<ll> boundry_guys;
    boundry_guys.pb(a[0]);
    boundry_guys.pb(a[n-1]);
    for(ll i=n-2; boundry_guys.size()<2*m; i--){
        boundry_guys.pb(a[gaps[i].ss]);
        boundry_guys.pb(a[gaps[i].ss+1]);
    }
    sort(all(boundry_guys));
    ll ans=0;
    for(ll i=0; i<2*m; i+=2){
        ans+= (boundry_guys[i+1]-boundry_guys[i]);
        //cout << boundry_guys[i+1] << ' ' << boundry_guys[i]  << endl;
    }
    o1(ans);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}