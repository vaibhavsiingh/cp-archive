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
const ll inf = 1e15;

void sol(){
    ll n,m;
    i2(n,m);
    vector<vector<pll>> adj(n+1);
    //vll indeg(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
      //  indeg[y]++;
    }

    vector<vll> info(n+1,vll(4));
    for(ll i = 1; i <= n; i++) {
        info[i] = {inf,inf,inf,-1};
    }
    info[1] = {0,1,0,0};
    priority_queue<vll,vector<vll>, greater<vll>> pq;
    pq.push({0,1,0,0,1});
    while(!pq.empty()){
        vll x = pq.top();
        pq.pop();
        if(x[0]>info[x[4]][0]) continue;
        ll curr = x[4], cost = x[0];
        for(auto [nd,wt]:adj[curr]){
            if(info[nd][0]>cost+wt){
                info[nd] = {cost+wt,info[curr][1],info[curr][2]+1,info[curr][3]+1};
//o1(nd);
              //  oArray(info[nd],4);
                pq.push({info[nd][0],info[nd][1],info[nd][2],info[nd][3],nd});
            }
            else if(info[nd][0]==cost+wt){
                info[nd][1]=(info[curr][1]+info[nd][1])%MOD;
                info[nd][2] = min(info[nd][2],info[curr][2]+1);
                info[nd][3] = max(info[nd][3],info[curr][3]+1);
               // o1(nd);
                 //oArray(info[nd],4);
              //  pq.push({info[nd][0],info[nd][1],info[nd][2],info[nd][3],nd});
            }
        }
    }

    // for(ll j=1; j<=n; j++){
    //     oArray(info[j],4);
    // }
    oArray(info[n],4);



}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}