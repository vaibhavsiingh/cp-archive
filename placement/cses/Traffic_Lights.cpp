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
    ll n,q;
    cin >> n >> q;

    set<ll> tls;
    multiset<ll> sizes;
    sizes.insert(n);
    tls.insert(0);
    tls.insert(n);

    while(q--){
        ll pos;
        cin >> pos;

        auto itr = tls.lower_bound(pos);
        ll aage = *itr;
        itr--;
        ll piche = *itr;

        auto to_erase = sizes.find(aage-piche);
        if(to_erase == sizes.end()){
            o1("chud gye guru");
            continue;
        }
        sizes.erase(to_erase);
        tls.insert(pos);
        sizes.insert(aage-pos);
        sizes.insert(pos-piche);
        cout << (*sizes.rbegin()) << ' ';
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}