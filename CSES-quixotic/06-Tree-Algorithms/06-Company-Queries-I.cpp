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

vector<vll> adj;
vector<vll> par;

void sol(){
    ll n,q;
    cin >> n >> q;
    adj.resize(n+1);
    par.resize(n+1, vll(18));
    for(ll i = 0; i < n-1; i++) {
        ll x;
        cin >> x;
        adj[x].pb(i+2);
        adj[i+2].pb(x);
        par[i+2][0] = x;
    }
    for(ll i=1; i<18; i++){
        for(ll nd=1; nd<=n; nd++){
            par[nd][i] = par[par[nd][i-1]][i-1];
        }
    }
  

    while(q--){
        ll nd, k;
        cin >> nd >> k;
        ll p = nd;
        ll x = 17;
        while(x>=0 && k>0){
            ll nm = (1<<x);
          //  o2(nm,k);
            if(nm<=k) {
                p = par[p][x];
                k-=nm;
            }
            x--;
        }
        if(p==0) o1(-1);
        else o1(p);
    }
    

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}