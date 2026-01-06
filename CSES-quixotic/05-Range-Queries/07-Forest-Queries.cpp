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
#define debug1(a) cout << a << endl
#define debug2(a, b) cout << a << ' ' << b << endl

const ll MOD = 1000000007;
const ll INF = 1e18;

vector<vll> a;
vector<vll> tree;
ll n;

void build(ll nd, ll t_idx, ll u, ll l, ll r){
    if(l==r){
        tree[t_idx][nd] = a[u][l];
        return;
    }
    ll md = (l+r)/2;
    build(2*nd, t_idx, u, l, md);
    build(2*nd+1, t_idx, u, md+1, r);
    tree[t_idx][nd] = tree[t_idx][2*nd+1]+tree[t_idx][2*nd];
}

ll query(ll nd, ll tree_idx, ll l, ll r, ll ql, ll qr){
    if(qr<l || r<ql) return 0;
    if(ql<= l && r <= qr) return tree[tree_idx][nd];
    ll md = (l+r)/2;
    ll x = query(2*nd, tree_idx, l, md, ql, qr);
    ll y = query(2*nd+1, tree_idx, md+1, r, ql, qr);
    return x+y;
}

void build2d(ll node, ll u, ll d){
    if(u==d){
        build(1, node, u, 0, n-1);
        return;
    }
    ll md = (u+d)/2;
    build2d(2*node, u, md);
    build2d(2*node+1, md+1, d);
    for(ll i=1; i<=4*n; i++){
        tree[node][i] = tree[2*node][i]+tree[2*node+1][i];
    }
}

ll query2d(ll nd, ll u, ll d, ll qu, ll qd, ll ql, ll qr){
    
    if(qd<u || d<qu) return 0;
    if(qu<= u && d<= qd) return query(1, nd, 0, n-1, ql, qr);
    ll md = (u+d)/2;
    ll x = query2d(2*nd, u, md, qu, qd, ql, qr);
    ll y = query2d(2*nd+1, md+1, d, qu, qd, ql, qr);
    return x+y;
}



void sol(){
    ll q;
    i2(n,q);
    tree.resize(4*n+1, vll(4*n+1));    
    vector<string> forest(n);
    for(ll i = 0; i < n; i++) {
        cin >> forest[i];
    } 
    
    a.resize(n, vll(n));
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<n; j++){
            if(forest[i][j]=='*') a[i][j] = 1;            
        }
    }
    build2d(1, 0, n-1);    
    while(q--){
        ll y1,y2,x1,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        y2--;
        x1--;
        x2--;
        o1(query2d(1,0, n-1, y1, y2, x1, x2));
        
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}