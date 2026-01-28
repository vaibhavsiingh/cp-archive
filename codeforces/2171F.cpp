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

vector<long long> mntree, arr, mxtree;

void build(ll node, ll l, ll r){
    if(l==r){
        mntree[node] = arr[l];
        mxtree[node] = arr[l];
    }
    else{
        ll mid = (l+r)/2;
        build(2*node,l,mid);
        build(2*node+1,mid+1,r);
        mntree[node] = min(mntree[2*node], mntree[2*node+1]);
        mxtree[node] = max(mxtree[2*node], mxtree[2*node+1]);
    }
}

ll mn_query(ll node, ll l, ll r, ll ql, ll qr){
    if(qr<l || ql>r) return INF;
    if(ql<=l && r<=qr) return mntree[node];
    ll md = (l+r)/2;
    ll x = mn_query(2*node,l,md,ql,qr);
    ll y = mn_query(2*node+1,md+1,r,ql,qr);
    return min(x,y);
}

ll mx_query(ll node, ll l, ll r, ll ql, ll qr){
    if(qr<l || ql>r) return 0;
    if(ql<=l && r<=qr) return mxtree[node];
    ll md = (l+r)/2;
    ll x = mx_query(2*node,l,md,ql,qr);
    ll y = mx_query(2*node+1,md+1,r,ql,qr);
    return max(x,y);
}



void sol(){
    ll n;
    cin >> n;
    arr.resize(n);
    mntree.resize(4*n, INF);
    mxtree.resize(4*n);
    vll mp(n+1);
    iArray(arr,n);  
    for(ll i = 0; i < n; i++) {        
        mp[arr[i]] = i;        
    }
    build(1,0,n-1);
    ll i=n-1;
    vector<pll> edges;
    while(i>=0){
        ll mn = mn_query(1, 0, n-1, 0, i);
        ll mn_idx = mp[mn];
        for(ll j=mn_idx+1; j<=i; j++){
           
            edges.pb({arr[j], mn});
        }
        if(mn==1){
            if(mn_idx==n-1) {
                o1("No");
                return;
            }               
        }
        else{
            ll mx = mx_query(1, 0, n-1, i+1, n-1);
            if(mx<mn){
                o1("No");
                return;
            }
           
            edges.pb({mn,mx});
        }
        i = mn_idx-1;
    }
    o1("Yes");
    for(auto [x,y]: edges){
        o2(x,y);
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    for(ll i = 0; i < T; i++) {        
        sol();
    }
}