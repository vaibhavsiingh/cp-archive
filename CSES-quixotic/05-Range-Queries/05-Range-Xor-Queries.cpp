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

const ll MOD = 1000000007;
const int INF = 1e9+1;

vll a;
vector<ll> tree;


void build(ll node, ll l, ll r){
    if(l==r) {
        tree[node] = a[l];
        return;
    }
    ll md = (l+r)/2;
    build(2*node, l, md);
    build(2*node+1, md+1, r);
    tree[node] = tree[2*node]^tree[2*node+1];
}

ll query(ll node, ll l, ll r, ll ql, ll qr){
    if(ql>r || qr<l) return 0;
    if(ql<= l && r<= qr) return tree[node];
    ll md = (l+r)/2;
    ll x = query(2*node, l, md, ql, qr);
    ll y = query(2*node+1, md+1, r, ql, qr);
    return x^y;
}

void sol(){
    ll n,q;
    i2(n,q);
    a.resize(n);
    iArray(a,n);
    tree.resize(4*n+1);

    build(1, 0, n-1);
    while(q--){
        ll x,y;
        i2(x,y);
        x--;
        y--;
        o1(query(1,0,n-1,x,y));
    }


}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}