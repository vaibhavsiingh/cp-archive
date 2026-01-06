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

// void bfs(ll nd, vector<vll>& adj, vll& dist){
//     dist[nd] = 0;
//     queue<ll> q;
//     q.push(nd);
//     for
// }
vector<vll> adj;
vll dist;

ll recurse(ll nd, ll par){
  //  o1(nd);
    ll ret = nd, mx = 0;
    for(auto c: adj[nd]){
        if(c!=par){
            ll x = recurse(c, nd);
            if(dist[c]+1>mx){
                mx  = dist[c]+1;
                ret = x;
            }
        }
    }
    dist[nd] = mx;
    return ret;
}

void sol(){
    ll n;
    cin >> n;
    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }    
    dist.resize(n+1);
    ll nd2 = recurse(1,0);
    dist.resize(n+1,0);
    
    recurse(nd2,0);
    o1(dist[nd2]);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}