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
const int minf = -1e18;
 
const ll MOD = 1000000007;
 
void sol(){
    ll n,m;
    i2(n,m);
    vector<vll> adj(n+1);
    vll indegree(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        indegree[y]++;
    }
    queue<ll> q;
    vll size(n+1,minf);
    for(ll i = 1; i <= n; i++) {
        if(indegree[i]==0) {
            q.push(i);
        }
    }
 
    vll parent(n+1);
    size[1]= 0;
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        for(ll y:adj[x]){
            indegree[y]--;
            if(size[y]<size[x]+1){
                size[y]=size[x]+1;
                parent[y]=x;
            }
            if(indegree[y]==0){
                q.push(y);
            }
            
        }
    }
    if(size[n]<0){
        o1("IMPOSSIBLE");
        return;
    }
 
    ll idx = n;
    vll path;
    while(idx!=0){
        path.pb(idx);
        idx = parent[idx];
    }
    reverse(path.begin(),path.end());
    o1(path.size());
    oArray(path,path.size());
}
 
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}
