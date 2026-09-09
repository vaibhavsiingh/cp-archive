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
    vector<vll> chln(n+1);
    vll count_v(n+1,0);
    
    for (ll i = 2; i <= n; i++) {
        ll x;
        cin >> x;        
        chln[x].push_back(i);
    }

    auto count = [&](auto&& self, int nd) -> void {
        assert(1 <= nd && nd <= n);

        for (ll c : chln[nd]) {            
            self(self, c);
            count_v[nd] += count_v[c] + 1;
        }
    };

    count(count, 1);
    for(ll i = 0; i < n; i++) {
        cout << count_v[i+1] << ' ';
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}