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

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);
    ll kk;
    for(ll i = 0; i < n; i++) {
        cin >> kk;
    }
   // reach;
    sort(all(a));
    ll p1=0, p2=0;
    ll n_stars = 0;
    vll next(n);
    vector<pll> stars_saved(n);

    while(p1<n){
       // cout << 1 << endl;
        while(p2 <n && a[p1]+k>=a[p2]) {
          //  cout << 2 << endl;
            p2++;
            n_stars++;
        }
        if(p2==n) next[p1] = INF;
        else next[p1] = p2;
        stars_saved[p1].ff = n_stars;
        stars_saved[p1].ss = p1;
        n_stars--;
        p1++;
    }
    vector<pll> stars_saved_copy = stars_saved;
    sort(stars_saved.rbegin(),stars_saved.rend());
    
    ll pos1 =0, pos2 = 0;
    ll mx = -INF;
    // for(ll i = 0; i < n; i++) {
    //     cout << stars_saved[i].ff << ' ' << stars_saved[i].ss << endl;
    // }
    for(; pos1 <n && pos2<n; pos1++){
      //  cout << 3 << endl;
        while(pos2<n && stars_saved[pos2].ss<next[pos1]) pos2++;
        if(pos2==n) {
            mx = max(stars_saved_copy[pos1].ff,mx);
        }
        else mx = max(stars_saved_copy[pos1].ff+stars_saved[pos2].ff,mx);
    }
    o1(mx);
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