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
    vll path;
    for(ll i = 1; i <= n; i++) {
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        path.pb(x);
        for(ll y:adj[x]){
            indegree[y]--;
            if(indegree[y]==0){
                q.push(y);
            }
        }
    }
    for(ll i = 1; i <= n; i++) {
        if(indegree[i]){
            o1("IMPOSSIBLE");
            return;
        }
    }
    oArray(path,n);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}