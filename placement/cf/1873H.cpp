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

void sol(){
    int n,sa,sb;
    cin >> n >> sa >> sb;
    vector<vll> adj(n+1);

    for(ll i = 0; i < n; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);    
    }

    vll parent(n+1,-1);
    parent[1] = 0; 
    queue<ll> q;
    q.push(1);
    int a=-1,b=-1;
    while(!q.empty()){
        ll nd = q.front();
        q.pop();

        for(ll nxt: adj[nd]){
            if(nxt == parent[nd]) continue;
            if(parent[nxt]!=-1){
                a = nxt;
                b = nd;
                break;
            }
            parent[nxt] = nd;
            q.push(nxt);
        }
        if(a!=-1) break;
    }
    //reach;
    
    vll inCycle(n+1);
  //  oArray(parent,n+1);
    vll pathA;
    vll isAncestor(n+1);
    while(a!=0){
        pathA.push_back(a);
        isAncestor[a] = 1;
        a = parent[a];        
    }    

    vll pathB;    
    ll lca = -1;
    while(b!=0){
        pathB.push_back(b);        
        if(isAncestor[b]) {
            lca =b;
            break;
        }
        b = parent[b];        
    }
    if(lca == -1){
        o1("loda");
        return;
    }
    int idx = 0;
    for(; idx<pathA.size(); idx++){
        if(pathA[idx] == lca){ break; }
    }

    if(idx == pathA.size()){
        o1("loda1");
    }

    idx--;
    while(idx>=0){
        pathB.push_back(pathA[idx]);
        idx--;
    }
    for(ll x: pathB) inCycle[x] = 1;

    q = {};
    q.push(sa);
    vll dist(n+1,-1);
    dist[sa] = 0;

    while(!q.empty()){
        ll nd = q.front();
        q.pop();

        for(ll nxt: adj[nd]){
            if(dist[nxt]!=-1) continue;
            
            dist[nxt] = dist[nd]+1;
            q.push(nxt);
        }        
    }

    bool done = false;

    q= {};
    q.push(sb);
    vll dist2(n+1,-1);
    dist2[sb] = 0;
    if(inCycle[sb] && dist2[sb] < dist[sb]) done = true;

    while(!q.empty() && !done){
        ll nd = q.front();
        q.pop();

        for(ll nxt: adj[nd]){
            if(dist2[nxt]!=-1) continue;
            dist2[nxt] = dist2[nd]+1;
            if(inCycle[nxt] && dist2[nxt] < dist[nxt]) done = true;
            q.push(nxt);
        }        
    }

    if(done){
        o1("YES");
    }
    else{
        o1("NO");
    }

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