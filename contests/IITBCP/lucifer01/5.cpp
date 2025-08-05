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

void bfs(vector<vll>& adj, vll& visited, ll start){
    queue<ll> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        ll a=q.front();
        q.pop();
        for(ll child:adj[a]){
            if(visited[child]>=0) continue;
            visited[child] = visited[a]+1;
            q.push(child);
        }
    }
    return;
}

ll specialbfs(vector<vll>& adj, vll& visited, ll start, vll& A, vll& B){
    queue<ll> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        ll a=q.front();
        q.pop();
        for(ll child:adj[a]){
            if(visited[child]>=0 || A[child]<=B[child]) continue;
            visited[child] = visited[a]+1;
            q.push(child);
        }
    }
    ll mx = -1;
    for(int i=1; i<visited.size(); i++){
        if(visited[i]>=0) mx = max(mx, A[i]);
    }
    
    return mx;
}

void sol(){
    ll n,s;
    i2(n,s);
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vll distA(n+1,-1), distB(n+1,-1);
    bfs(adj,distA,1);
    bfs(adj,distB,s);

    vll visited(n+1,-1);
    ll ans = 2ll*specialbfs(adj,visited,s, distA, distB);

    o1(ans);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}