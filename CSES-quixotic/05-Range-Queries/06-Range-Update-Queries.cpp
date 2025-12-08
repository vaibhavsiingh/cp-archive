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

vll a;
vector<ll> tree;


void update(ll node, ll l, ll r, ll ql, ll qr, ll val){
    if(r<ql || qr<l) return;
    if(ql<=l && r<= qr){
        tree[node] += val;
        return;
    }
    ll md = (l+r)/2;
    update(2*node, l, md, ql, qr, val);
    update(2*node+1, md+1, r, ql, qr, val); 
}

ll query(ll node, ll l, ll r, ll idx ){
    if(l==idx && r ==idx) return a[idx]+tree[node];
    ll md = (l+r)/2;
    if(idx<=md)return query(2*node, l, md, idx)+tree[node];
    else return query(2*node+1, md+1, r, idx)+tree[node];
}


void sol(){
    ll n,q;
    i2(n,q);
    a.resize(n);
    iArray(a,n);
    tree.resize(4*n+1);

    while(q--){
        ll qq;
        cin >> qq;
        if(qq==1){
            ll l,r,val;
            cin >> l >> r >> val;
            update(1, 0, n-1, --l,--r,val);
        }
        else{
            ll idx;
            cin >> idx;
            idx--;
            o1(query(1,0,n-1,idx));
        }
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}