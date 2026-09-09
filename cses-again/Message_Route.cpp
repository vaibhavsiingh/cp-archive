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
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n,m;
    cin >> n >> m;

    vector<vll> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<ll> q;
    q.push(1);
    vll visited(n+1,0);
    visited[1] = 1;
    vll parent(n+1,-1);
    parent[1] = 0;

    while(!q.empty()){
        ll nd = q.front();
        q.pop();

        for(ll nxt : adj[nd]){
            if(!visited[nxt]){
                visited[nxt] = 1;
                q.push(nxt);
                parent[nxt] = nd;
            }
        }
    }

    if(visited[n] == 0){
        o1("IMPOSSIBLE");
        return;
    }
    vll path = {n};
    ll curr = n;
    while(curr != 1){
        curr = parent[curr];
        path.push_back(curr);
    }
    o1(path.size());
    reverse(all(path));
    oArray(path, path.size());

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}