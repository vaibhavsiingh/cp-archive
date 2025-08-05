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



void bfs(vector<vll>& adj, vll& visited, ll start, vll& parent, vll& used, vll& seen){
    queue<ll> q;
    q.push(start);
    visited[start] = 0;
    while(!q.empty()){
        ll a=q.front();
   //     o1(a);
        q.pop();
        for(ll child:adj[a]){
          //  o1(child);
            if(visited[child]>=0 || used[child]) continue;
            visited[child] = visited[a]+1;
            parent[child] = a;
            seen[child] = 1;
            q.push(child);
        }
    }
    return;
}



void do_stuff(vector<vll>& adj, ll start, ll n, vll& used, vector<vll>& coln, vll& seen){
    vll visited(n+1,-1);
    vll parent(n+1,0);
    bfs(adj,visited, start,parent, used, seen);
    ll mx_d=0, mx_idx=1;
    for(int i=1; i<=n; i++){
        if(mx_d<=visited[i]){
            mx_d = visited[i];
            mx_idx = i;
        }
    }
    ll x = mx_idx;
    for(ll i = 0; i < n+1; i++) {
        visited[i] = -1;
    }
    parent[x] = -1;
   
    mx_d=0, mx_idx=1;
    for(int i=1; i<=n; i++){
        if(mx_d<=visited[i]){
            mx_d = visited[i];
            mx_idx = i;
        }
    }
    ll y=mx_idx;

    while(y!=x){
        used[y] = 1;
        y = parent[y];
    }
    used[x] = 1;
    
    coln.pb({mx_d+1, max(mx_idx,x), min(mx_idx, x)});
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
    
    vll used(n+1);
    vector<vll> coln;
    while(true){
       ll start_node = -1;
        for(int i=1; i<=n; i++){
            if(!used[i]){
                start_node = i;
                break;
            }
        }
        if(start_node==-1) break;
        vll seen(n+1);
        for(; start_node<=n; start_node++)if(!seen[start_node] && !used[start_node])
                                        do_stuff(adj, start_node, n, used,coln, seen);
    }
    sort(coln.rbegin(), coln.rend());
    for(auto v:coln){
        cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ';
    }
    cout << "\n";
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
}   