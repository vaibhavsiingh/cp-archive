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

vll val;
vector<vll> adj;
vll flat_tree;
vll seg_tree;
vll tin, tout;

void dfs(ll nd, ll p){
    tin[nd] = flat_tree.size();
    flat_tree.pb(nd);
    for(ll c: adj[nd]){
        if(c!=p) dfs(c,nd);
    }
    tout[nd] = flat_tree.size()-1;
}

void build(ll node, ll l, ll r){
    if(l==r){
        seg_tree[node] = val[flat_tree[l]];
        return;
    }
    ll md  = (l+r)/2;
    build(2*node, l, md);
    build(2*node+1, md+1, r);
    seg_tree[node] = seg_tree[2*node]+seg_tree[2*node+1];
}

void update(ll node, ll l, ll r, ll idx, ll val){
    if(idx < l || idx > r) return;
    if(l==idx && r==idx){
        seg_tree[node] = val;
        return;
    }
    ll md = (l+r)/2;
    update(2*node, l, md, idx, val);
    update(2*node+1, md+1, r, idx, val);
    seg_tree[node] = seg_tree[2*node]+seg_tree[2*node+1];
}

ll query(ll node, ll l, ll r, ll ql, ll qr){
    if(qr<l || r<ql) return 0;
    if(ql<=l && r<=qr) return seg_tree[node];    
    ll md = (l+r)/2;
    ll x = query(2*node, l, md, ql, qr);
    x += query(2*node+1, md+1, r, ql, qr);
    return x;
}

void sol(){
    ll n,q;
    cin >> n >> q;

    val.resize(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> val[i+1];
    }

    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    tin.resize(n+1);
    tout.resize(n+1);
    dfs(1,0);
    
    seg_tree.resize(4*n+1);
    build(1,0,n-1);
    
    while(q--){
        ll qt;
        cin >> qt;
        if(qt==1){
            ll nd, new_val;
            i2(nd, new_val);
            update(1,0,n-1,tin[nd],new_val);
        }
        else{
            ll nd;
            cin >> nd;
            ll ans = query(1,0,n-1,tin[nd], tout[nd]);            
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