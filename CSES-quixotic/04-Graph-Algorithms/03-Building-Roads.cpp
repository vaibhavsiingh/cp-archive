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

void dfs(ll x, ll flag){
    if(visited[x]) return;
    visited[x] = flag;
    for(ll child: adj[x]) {
        dfs(child,flag);
    }
    return;
}

void sol(){
    
    i2(n,m);
    adj.resize(n+1);
    visited.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]){
            dfs(i,i);
        }
    }
    set<ll> s;
    for(ll i = 1; i <= n; i++) {
        s.insert(visited[i]);
    }
    ll pivot = *s.begin();
    o1(s.size()-1);
    for(auto itr = ++s.begin(); itr!=s.end(); itr++){
        o2(pivot,*itr);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}