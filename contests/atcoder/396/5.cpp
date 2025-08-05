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

vector<vector<pll>> adj;
vll A;
vll ans;
vll visited;

vll bfs(ll node){
    queue<ll> q;
    q.push(node);
    A[node] = 0;
    vll comp;
    visited[node] = 1;
    comp.pb(node);
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
       // o1(x);
        for (auto [nxt, wt] : adj[x]) {
            if (!visited[nxt]) {
                q.push(nxt);
                visited[nxt] = 1;
                A[nxt] = A[x]^wt;
                comp.pb(nxt);
            }
            else{
                if(A[nxt]!=(A[x]^wt)){
                    o1(-1);
                    exit(0);
                }
            }
        }
    }
    return comp;
}


void sol(){
    ll n,m;
    i2(n,m);
    adj.resize(n);
    A.resize(n,0);
    visited.resize(n,0);
    ans.resize(n,0);
  //  vector<vll> adjmat(n+1,vll(n+1));
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        x--;y--;
      //  if(x==y) continue;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
        // adjmat[x][y] = z;
        // adjmat[y][x] = z;
    }

    for(ll i=0; i<n; i++){
        if(visited[i]) continue;
        vll comp = bfs(i);
        for(ll bit=0; bit<30; bit++){
            ll count=0;
            for(ll nd:comp){
                if(A[nd]&(1<<bit)) count++;
            }
            if(count<comp.size()-count){
                for(ll nd:comp){
                    if(A[nd]&(1<<bit)){
                        ans[nd] |= (1<<bit);
                    }
                }
            }
            else{
                for(ll nd:comp){
                    if(!(A[nd]&(1<<bit))){
                        ans[nd] |= (1<<bit);
                    }
                }
            }
        }
    }



    for(ll i = 0; i < n; i++) {
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