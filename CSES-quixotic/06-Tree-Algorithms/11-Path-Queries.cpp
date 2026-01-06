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
vll valueNode;
vll valuePath;
vll flattened_tree;
vll seg_tree;
vll tin, tout;
vll extra;

void dfs(ll nd, ll p){
    tin[nd] = flattened_tree.size();
    flattened_tree.pb(nd);
    valuePath[nd] = valuePath[p]+valueNode[nd];
    for(ll c: adj[nd]){
        if(c!=p) dfs(c,nd);
    }
    tout[nd] = flattened_tree.size()-1;
}

void build(ll node, ll l, ll r){
    if(l==r) {        
        seg_tree[node] = valuePath[flattened_tree[l]];
        return;
    }
    
    ll md = (l+r)/2;
    build(2*node, l, md);
    build(2*node+1, md+1, r);    
}

void update(ll node, ll l, ll r, ll ul, ll ur, ll ext){
    if(ur<l || r<ul) return;
    if(ul<=l && r<=ur){
        extra[node] += ext;
        return;
    }
    ll md = (l+r)/2;
    update(2*node, l, md, ul, ur, ext);
    update(2*node+1, md+1, r, ul, ur, ext);
}

ll query(ll node, ll l, ll r, ll idx){
    if(l==r && r==idx){
        return extra[node]+seg_tree[node];
    }
    
    ll md = (l+r)/2;
    if(idx<=md){
        return extra[node]+query(2*node, l, md,idx);
    }
    else return extra[node]+query(2*node+1, md+1, r, idx);

}

void sol(){
    ll n,q;
    cin >> n >> q;

    valueNode.resize(n+1);
    for(ll i=1; i<=n; i++) cin >> valueNode[i];

    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    tin.resize(n+1);
    tout.resize(n+1);
    valuePath.resize(n+1);
    dfs(1,0);
    
    seg_tree.resize(4*n+1);
    extra.resize(4*n+1);
    build(1, 0, n-1);
   
    while(q--){
        ll qt;
        cin >> qt;   
        if(qt==1){
            ll nd, new_val;
            i2(nd, new_val);
            update(1, 0, n-1, tin[nd], tout[nd],new_val- valueNode[nd]);
            valueNode[nd] = new_val;
        }
        else{
            ll nd;
            cin >> nd;
            ll ans = query(1, 0, n-1, tin[nd]);
            o1(ans);
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}