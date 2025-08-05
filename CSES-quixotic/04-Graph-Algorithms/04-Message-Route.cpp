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

const ll MOD = 1000000007;

ll n,m;
vector<vll> adj;
vector<ll> visited;
vector<ll> parent;
ll ans = 0;


void bfs(){
    queue<ll> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
        if(curr == n) return;
        for(ll child:adj[curr]){
            if(visited[child]) continue;
            visited[child] = 1;
            parent[child] = curr;
            q.push(child);
        }
    }
    return;
}


void sol(){
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1);
    parent.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs();
    if(!visited[n]){
        o1("IMPOSSIBLE");
        return;
    }
    stack<ll> path;
    path.push(n);
    ll ptr = n;
    while(ptr!=1){
        ptr = parent[ptr];
        path.push(ptr);
    }
    o1(path.size());
    while(!path.empty()){
        cout << path.top() <<  ' ';
        path.pop();
    }
    cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}