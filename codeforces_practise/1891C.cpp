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
    vll a(n);

    iArray(a,n);

    sort(all(a));

    ll l=0, r=n-1;
    ll x = 0;
    ll ans = 0;
    while(l<r){
        if(a[l] == 0) {
            l++;
            continue;
        }
        else if(a[r] == 0){
            r--;
            continue;
        }
        if(x + a[l] >= a[r]){
            int kill_first = a[r] - x;
            ans += kill_first;
            a[l] -= kill_first;
            
            ans++;
            r--;
            x = 0;            
        }
        else{
            ans += a[l];
            x += a[l];
            l++;
        }
    }
    if(l==r ){
        int kill = (a[l] - x) / 2 ;
        if(kill > 0) a[l] -= kill, ans += kill;
        if(x + kill > 0) a[l] -= (x+kill), ans += 1;
        ans += a[l];
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