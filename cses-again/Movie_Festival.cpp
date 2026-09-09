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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    vector<pll> mov(n);

    for(ll i = 0; i < n; i++) {
        cin >> mov[i].ff >> mov[i].ss;
    }

    sort(all(mov), [](pll a, pll b){
        if(a.ss == b.ss){
            return a.ff < b.ff;
        }
        else return a.ss < b.ss;
    });

    ll curr_time =0;
    ll cnt = 0;
    for(ll i = 0; i < n; i++) {
        if(mov[i].ff >= curr_time){
            cnt++;
            curr_time = mov[i].ss;
        }
    }
    o1(cnt);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}