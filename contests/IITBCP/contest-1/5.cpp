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

const ll MOD = 1000000007;
const ll INF = 1e18;

const int MAXN = 200000;
int n, m, a[MAXN];
pair<int,int> st[4*MAXN];


void build(int idx, int l, int r){
    if(l==r){
        st[idx] = {a[l],a[l]};
        return;
    }
    int mid = (l+r)>>1;
    build(idx<<1,l,mid);
    build((idx<<1)|1,mid+1,r);
    st[idx].first = min(st[idx<<1].first, st[(idx<<1)|1].first);
    st[idx].second = max(st[idx<<1].second, st[(idx<<1)|1].second);
}

int query(int idx, int l, int r, int i, int j, int x){
    if(l>j || r<i || (st[idx].first == st[idx].second && st[idx].first == x)) return -1;
    if(l==r) return l;
    int m = (l+r)>>1;
    int res = query(idx<<1,l,m,i,j,x);
    if(res!=-1) return res;
    else return query((idx<<1)|1,m+1,r,i,j,x);
}

void sol(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    build(1,0,n-1);
    while(m--){
        int l,r,x;
        cin>>l>>r>>x;
        int ans = query(1,0,n-1,l-1,r-1,x);
        
        cout<<(ans==-1? -1: ans+1)<<"\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}