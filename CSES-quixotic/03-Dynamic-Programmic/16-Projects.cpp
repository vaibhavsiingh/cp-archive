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
    vector<vll> v(n,vll(3));
    for(ll i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    map<ll,ll> m;
    sort(v.begin(), v.end(), [](const vector<ll> &a, const vector<ll> &b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    m[0] = 0;
    for(ll i=0; i<n; i++){
        auto x = m.lower_bound(v[i][0]);
        x--;
        m[v[i][1]] = max((--m.end())->second,x->second + v[i][2]);
    }
    o1((--m.end())->second);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}