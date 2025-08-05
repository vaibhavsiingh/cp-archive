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

ll modexp(ll a, ll b){
    if(b==0)return 1;
    if(b==1) return a;
    ll t = modexp(a,b/2);
    t = (t*t)%MOD;
    if(b&1){
        return (t*a)%MOD;
    }
    else return t;
}

void dfs(vector<vll>& adj, vll& parent, ll node, ll par, vll&depth){
    depth[node] = depth[par]+1;
    parent[node] = par;
    for(auto x: adj[node]){
        if(x!=par){
            dfs(adj,parent,x,node,depth);
        }
    }
}


void sol(){
    ll n;
    cin >> n;
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    ll onedegree=0;
    ll v1=0,v2=0;
    for(ll i=1; i<=n; i++){
        if(adj[i].size()==1 && i!=1){
         //   o1(i);
            onedegree++;
            if(v1==0){
                v1=i;
            }
            else if(v2==0){
                v2=i;
            }
            else break;
        }
    }
    if(onedegree>2){
        o1(0);
        return;
    }
    if(onedegree==1){
        o1(modexp(2ll,n));
        return;
    }

    vll parent(n+1), depth(n+1);
    dfs(adj,parent,1,0,depth);

    auto lca = [&](ll v1, ll v2){
        while(depth[v1]<depth[v2]){
            v2 = parent[v2];
        }
        while(depth[v1]>depth[v2]){
            v1 = parent[v1];
        }
        while(v1!=v2){
            v1 = parent[v1];
            v2 = parent[v2];
        }
        return v1;
    };

    ll cm = lca(v1,v2) ;
    ll cnt1 = depth[v1]-depth[cm]-1, cnt2 = depth[v2]-depth[cm]-1;
    if(cnt2==cnt1){
        ll ans = modexp(2,n-2*cnt1-1);
        o1(ans);
        return;
    }
    
    if(cnt1<cnt2){
        swap(cnt1,cnt2);
    }
    ll ans = (modexp(2,n-2*cnt2-3)+modexp(2,n-2*cnt2-2))%MOD;
    o1(ans);
    return;

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}