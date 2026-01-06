#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<int> vll;
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
vll freq;
vll tree;

void build(ll nd, ll l, ll r){
    if(l==r){
        tree[nd] = freq[l];
        return;
    }
    ll md = (l+r)/2;
    build(2*nd,l,md);
    build(2*nd+1,md+1,r);
    tree[nd] = tree[nd*2+1]+tree[2*nd];
}

void del(ll nd, ll l, ll  r, ll i){
    if(i<l || r<i) return;
    tree[nd]--;
    if(l==r){        
        return;
    }
    ll md = (l+r)/2;
    if(i<=md){
        del(2*nd,l,md,i);
        return;
    }
    else{
        del(2*nd+1,md+1,r,i);
    }
}

void add(ll nd, ll l, ll r, ll i){
    if(i<l || r<i) return;
    tree[nd]++;
    if(l==r){        
        return;
    }
    ll md = (l+r)/2;
    if(i<=md){
        add(2*nd,l,md,i);
        return;
    }
    else{
        add(2*nd+1,md+1,r,i);
    } 
}

ll query(ll nd, ll l, ll r, ll ql, ll qr){
    if(qr<l || r<ql) return 0;
    if(ql<=l&&r<=qr) return tree[nd];
    ll md = (l+r)/2;
    return query(2*nd, l, md, ql, qr)+ query(2*nd+1, md+1, r, ql, qr);
}


void sol(){
    ll n,q;
    cin >> n >> q;
    a.resize(n);
    freq.resize(1e7);
    tree.resize(4e7+1);
    iArray(a,n);

    multiset<ll> m;
    for(ll i = 0; i < n; i++) {
        m.insert(a[i]);
        freq[(a[i]-1)/100]++;
    }

    while(q--){
        char c;
        cin >> c;
        ll x,y;
        cin >> x >> y;
        if(c=='?'){
            ll nxt = (x+99)/100;
            ll prev = (x-99)/100;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}