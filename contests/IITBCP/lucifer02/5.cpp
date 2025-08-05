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

ll ans1=0;
ll ans2=0;
ll n;
ll ne=0,no=0;

void dfs(vector<vll>& adj, ll parent, vll& oddsz, vll& evensz, vll& depth, ll start){
    evensz[start] = 1;
    if(depth[start]%2==0) ne+=1;
    else no+=1;
    for(auto c:adj[start]){
        if(c==parent) continue;
        depth[c] = depth[start]+1;
        dfs(adj,start,oddsz, evensz, depth,c);
        ll s = evensz[c];
        evensz[start]+=evensz[c];
        ans1 += s*(n-s);
    }
}


void sol(){
    
    cin >> n;
    ans1=0;
    ans2=0;
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    
    vll oddsz(n+1), evensz(n+1), depth(n+1);
    dfs(adj,-1,oddsz,evensz,depth,1);

 //   o1(ans1);
 ll odd_pairs = ne*no;
    o1((ans1+odd_pairs)/2);



}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}