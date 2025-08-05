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
    ll n,m,k;
    cin >> n >> m >> k;
    vector<vector<pll>> adj(n+1);
    for(ll i=0; i<m; i++){
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
    }
    vector<priority_queue<ll>> dist(n+1);
    dist[1].push(0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        ll d=pq.top().ff, nd=pq.top().ss;
        pq.pop();
        if(dist[nd].top()<d) continue;
        for(auto [nxt,w]:adj[nd]){
            if(dist[nxt].size()<k){
                dist[nxt].push(d+w);
                pq.push({d+w,nxt});
            }
            else if(dist[nxt].top()>d+w){
                dist[nxt].pop();
                dist[nxt].push(d+w);
                pq.push({d+w,nxt});
            }
        }
       // cout << endl;
    }
    vll ans(k);
    for(ll i=0; i<k; i++){
        ans[i] = dist[n].top();
        dist[n].pop();
    }
    reverse(ans.begin(),ans.end());
    oArray(ans,k);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}