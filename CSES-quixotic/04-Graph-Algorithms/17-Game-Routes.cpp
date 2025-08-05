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
    vll indeg(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        indeg[y]++;
    }
    queue<ll> q;
    for(ll i=1; i<=n; i++) if(indeg[i]==0) q.push(i);
    vll count(n+1);
    count[1]=1;
    while(!q.empty()){
        ll nd = q.front();
        q.pop();
        for(ll nxt:adj[nd]){
            indeg[nxt]--;
            count[nxt]=(count[nxt]+count[nd])%MOD;
            if(indeg[nxt]==0){
                q.push(nxt);
            }
        }
    }

    o1(count[n]);
    
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}