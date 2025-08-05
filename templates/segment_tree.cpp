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
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rep0(i, n) for (ll i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

vector<long long> tree, arr;

void build(ll node, ll l, ll r){
    if(l==r){
        tree[node] = arr[l];
    }
    else{
        ll mid = (l+r)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

ll query(ll node, ll l, ll r, ll ql, ll qr){
    if(qr<l || ql>r) return 0;
    if(ql<=l && r<=qr) return tree[node];
    ll md = (l+r)/2;
    ll x = query(2*node,l,md,ql,qr);
    ll y = query(2*node+1,md+1,r,ql,qr);
    return x+y;
}

void update(ll node, ll l, ll r, ll idx, ll val){
    if(l==idx && r==idx) {
        tree[node] = val;
        return;
    }
    ll md = (l+r)/2;
    if(idx<=md){
        update(2*node,l,md,idx,val);
    }
    else{
        update(2*node+1,md+1,r,idx,val);
    }    
    tree[node] = tree[2*node] + tree[2*node+1];
}


void sol(){
    ll n,q;
    cin >> n >> q;
    arr.resize(n);
    tree.resize(4*n);

    iArray(arr,n);
    build(1,0,n-1);
    
    while(q--){
        ll q;
        cin >> q;
        if(q==1){
            ll idx, val;
            cin >> idx >> val;
            idx--;
            update(1,0,n-1,idx,val);
        }
        else{
            ll l,r;
            i2(l,r);
            l--,r--;
            cout << query(1,0,n-1,l,r) << "\n";
        }
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}