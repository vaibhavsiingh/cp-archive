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
    vector<vector<pll>> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    vll visited(n+1);
    ll cost = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [c,nd] = pq.top();
       // o2(c,nd);
        pq.pop();
        if(visited[nd]) continue;
        visited[nd]=1;
        cost += c;
       for(auto [nxt,wt]:adj[nd]){
        if(!visited[nxt]){
            pq.push({wt,nxt});
        }
       }
    }

    if (accumulate(visited.begin() + 1, visited.end(), 0) == n) {
        o1(cost);
    } else {
        o1("IMPOSSIBLE");
    }



}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}