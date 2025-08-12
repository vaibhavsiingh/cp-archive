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
vector<ll> fac;

void solve(int nd, int par, vector<vector<ll>>& adj, ll& ans){
    int multi_edge_nd=-1;
    int deg=0;
    for(auto nxt:adj[nd]){
        if(nxt==par) continue;
        if(adj[nxt].size()>1 && multi_edge_nd==-1) multi_edge_nd=nxt;
        else if(adj[nxt].size()>1 && multi_edge_nd!=-1){
            ans=0;
            return;
        }    
        deg++;    
    }
    if(multi_edge_nd==-1){
        ans=(ans+fac[deg])%MOD;
    }
    else{
        ans=(ans+fac[deg-1])%MOD;
        solve(multi_edge_nd,nd,adj,ans);
    }
}

void sol(){
    int n,m;
    cin >> n >> m;
    vector<vll> adj(n+1) ;
    for(ll i = 0; i < m; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fac.resize(n+1);
    fac[0]=1;
    for(int i=1;i<=n; i++){
        fac[i]=(fac[i-1]*i)%MOD;
    }
    vector<int> nodes(n);
    for(int i=0; i<n; i++){
        nodes[i] = i+1;
    }
    
    vector<int> vis(n+1);
    vis[1] = 1;
    queue<pair<int,int>> q;
    q.push({1,-1});
    while(!q.empty()){
        auto [x,par] = q.front();
        q.pop();
        for(auto nxt:adj[x]){
            if(nxt==par) continue;
            if(vis[nxt]!=0) {
                o1(0);
                return;
            }
            vis[nxt]=1;
            q.push({nxt,x});
        }
        
    }
    
    sort(nodes.begin(),nodes.end(),
        [&](int x, int y){
            return adj[x].size()>adj[y].size();
        }
    );
    
    ll ans = 0;
    int start = nodes[0];
    if(adj[start].size()==1){
        o1(2);
        return;
    }
    else if(adj[start].size()==2){
        o1(4);
        return;
    }
    int deg=0;
    vector<int> multi_nds;
    for(auto nxt:adj[start]){
        if(adj[nxt].size()>1 && multi_nds.size()<2) multi_nds.pb(nxt);
        else if(adj[nxt].size()>1 && multi_nds.size()==2){
            ans=0;
            o1(0);
            return;
        }    
        deg++;    
    }
    if(multi_nds.size()==0){
        ans=(ans+fac[deg])%MOD;
    }
    else if(multi_nds.size()==1){
        ans=(ans+fac[deg-1])%MOD;        
        ll temp = ans;
        solve(multi_nds[0],start,adj,ans);
        ll extra = ans-temp;`
        ans=(ans+extra)%MOD;
    }
    else{
        ans=(ans+fac[deg-2])%MOD;
        ll temp = ans;
        solve(multi_nds[0],start,adj,ans);
        solve(multi_nds[1],start,adj,ans);
        ll extra = ans-temp;
        ans=(ans+extra)%MOD;
    }
    o1((2ll*ans)%MOD);

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