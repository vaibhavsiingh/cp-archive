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

void rec(ll nd, vector<vll>& adj, vll& tot, ll p, ll& ans, ll k, ll n){
    tot[nd] = 1;
    for(ll c: adj[nd]){
        if(c!=p){
            rec(c,adj,tot,nd, ans, k, n);
            tot[nd] += tot[c];
        }
    }
    ll others = n - tot[nd];
    if(tot[nd]>=k){
        ans += others;                
    }
    ans+=1;
    for(ll c: adj[nd]){
        if(c!=p){
            ll num = tot[nd] - tot[c] + others;
            if(num>=k) ans+=tot[c];
        }
    }    
}

void sol(){
    ll n,k;
    cin >> n >> k;
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    vll tot(n+1);
    ll ans = 0;
    rec(1,adj,tot,0, ans, k, n);
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