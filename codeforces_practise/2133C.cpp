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
    vector<vll> len(n+1);
    ll mx_len = 0;
    for(ll x=1; x<=n; x++){
        cout << "? " << x << " " << n << " ";
        for(ll i=1; i<=n; i++) cout << i << " ";
        cout << endl;
        ll l;
        cin >> l;
        len[l].pb(x);
        mx_len = max(mx_len,l);
    }
    vll path;
    ll curr_node = len[mx_len][0];
    path.pb(curr_node);
    for(ll l=mx_len-1; l>=1; l--){        
        ll i=0;
        for(; i<len[l].size(); i++){
            ll maybe_next_node = len[l][i];
            cout << "? " << curr_node << " 2 " << curr_node << ' ' << maybe_next_node << endl;
            ll in;
            cin >> in;
            if(in == 2){
                break;                
            }
        }
        path.pb(len[l][i]);
        curr_node = len[l][i];
    }
    cout << "! " << mx_len << " ";
    for(ll x: path) cout << x << ' ';
    cout << endl;
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