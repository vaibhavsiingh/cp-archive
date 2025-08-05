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

ll n,m;
vector<vector<pll>> adj;
ll ans = LLONG_MAX;

void helper(ll node,ll dest, ll curr_xor, vector<ll>& visited){
    if(node == dest){
        ans = min(ans,curr_xor);
        return;
    }

    visited[node] = 1;
    for(auto [next, w]:adj[node]){
        if(!visited[next]){
            helper(next,dest,curr_xor^w,visited);
        }
    }
    visited[node] = 0;

}


void sol(){
    ll n,m;
    i2(n,m);
    adj.resize(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    vector<ll> visited(n+1);
    helper(1,n,0,visited);
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}