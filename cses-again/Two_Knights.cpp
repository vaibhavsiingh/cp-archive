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
    vll ans = {0,6,28,96,252};
    for(ll i=1; i<=min((ll)5,n); i++){
        cout << ans[i-1] << '\n';
    }
    ll curr = 252;
    for(ll i=6; i<=n; i++){
        ll to_remove_1 = ((ll)22 + (i-(ll)5)*(ll)8);
        ll total_1 = (2*i-1)*(i-1)*(i-1);
     //   o2(to_remove_1, total_1);
        ll actual_1 = total_1 - to_remove_1;
        ll actual_2 = ((2*i-1)*(2*i-2))/2 - 2;
       // o2("as",actual_2);
        curr += actual_1 + actual_2;
        o1(curr);
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}