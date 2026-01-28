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

const ll MOD = 998244353;
const ll INF = 1e18;

void sol(){
    ll n,m;
    cin >> n >> m;
    vector<pll> a(n+1);
    vll val(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> a[i+1].ff;
        val[i+1] = a[i+1].ff;
        a[i+1].ss = i+1;
    }

    vector<vll> in(n+1), out(n+1);
    for(ll i=0; i<m; i++){
        ll x,y;
        cin >> x >> y;
        in[y].pb(x);
        out[x].pb(y);        
    }

    sort(all(a));
    unordered_map<ll,unordered_map<ll,ll>> len;
    for(ll x=1; x<=n; x++){
        for(ll nd: out[x]){
            len[nd][x] += 1;
        }
    }

    for(ll i=0; i<n; i++){
        ll nd = a[i].ss;
        unordered_map<ll,ll> mp;
        for(ll par: in[nd]){
            ll sm = val[par]+val[nd];
            mp[sm] = (len[nd][par]+ mp[sm])%MOD;
        }
        for(ll chld: out[nd]){
            if(mp.find(val[chld])!=mp.end()){                                 
                len[chld][nd] = (mp[val[chld]]+len[chld][nd])%MOD;                
            }
        }
    }
    ll ans = 0;
    for(ll x=1; x<=n; x++){
        for(ll nd: out[x]){
            ans = (ans+len[nd][x])%MOD;
        }
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