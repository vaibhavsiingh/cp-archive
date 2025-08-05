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
vll visited;
vll teams;

ll bfs(ll start){
    queue<ll> q;
    q.push(start);
    visited[start] = 1;
    teams[start] = 1;
    while(!q.empty()){
        ll curr = q.front();
        q.pop();
    //    o2("Currently visiting", curr);
        for(ll nxt:adj[curr]){
            if(visited[nxt]){
                if(teams[curr]==teams[nxt]){
                    o1("IMPOSSIBLE");
                    return 0;
                }
                continue;
            }
            visited[nxt]=1;
            teams[nxt] = (teams[curr]==1) ? 2 : 1;
            q.push(nxt);
        }
    }
    return 1;
}

void sol(){
    i2(n,m);
    adj.resize(n+1);
    visited.resize(n+1);
    teams.resize(n+1);

    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            if(!bfs(i)) return;
        }
    }
    for(ll i = 1; i <= n; i++) {
        cout << teams[i] << ' ';
    }
    cout << "\n";


}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}