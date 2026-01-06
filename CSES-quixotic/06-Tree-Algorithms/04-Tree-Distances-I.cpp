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
vector<vll> dist;
vector<vll> distNodes;
vll ans;

void recurse(ll nd, ll par){
    ll mx = 0, mxNd = 0, mx2 = 0, mx2Nd = 0;
    for(ll c: adj[nd]){
        if(c!=par){
            recurse(c,nd);
            ll d = dist[c][0]+1;
            if(d>=mx){
                mx2 = mx;
                mx2Nd = mxNd;
                mx = d;
                mxNd = c;
            }
            else if(d>mx2){
                mx2 = d;
                mx2Nd = c;
            }            
        }
    }
    dist[nd] = {mx,mx2};
    distNodes[nd] = {mxNd,mx2Nd};
}

void traverse(ll nd, ll par, ll mx){
    ans[nd] = max(mx, dist[nd][0]);
    for(ll c: adj[nd]){
        if(c!=par){
            if(c==distNodes[nd][0]){
                traverse(c,nd,1+max(mx,dist[nd][1]));
            }
            else traverse(c,nd,1+max(mx,dist[nd][0]));
        }
    }
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
    dist.resize(n+1, vll(2));
    distNodes.resize(n+1, vll(2));
    recurse(1,0);
    
    ans.resize(n+1,0);
    traverse(1,0,0);
    for(ll i=1; i<=n; i++){
        cout << ans[i] << ' ';    
    }
    o1("");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}