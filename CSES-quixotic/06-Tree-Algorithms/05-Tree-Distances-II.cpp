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

vector<vll> adj;
vector<vll> numNd;
vll ans;
ll n;

ll countNodes(ll nd, ll p){
    ll sm = 1;
    for(ll c: adj[nd]){
        if(c!=p){
            ll cnt =countNodes(c,nd);
            sm += cnt;
            numNd[nd].pb(cnt);
        }
        else numNd[nd].pb(0);
    }
    return sm;
}

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

void calDist(ll nd, ll p, ll sm){
    ans[nd] = sm;
    for(ll i=0; i<adj[nd].size(); i++){
        ll c = adj[nd][i];
        if(c!=p){
            calDist(c,nd,sm-2ll*numNd[nd][i]+ n);
        }
    }
}

void sol(){    
    cin >> n;
    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    numNd.resize(n+1);
    countNodes(1,0);
    vll visited(n+1,-1);
    bfs(adj, visited, 1);
    ll sm = accumulate(all(visited),1ll);

    ans.resize(n+1);
    calDist(1,0,sm);
    for(ll i=1; i<=n; i++){
        cout << ans[i] << ' ';
    }
    o1("");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}