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

void sol(){
    ll n;
    cin >> n;
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll dist(n+1,0);

    auto bfs = [&](int nd){
        queue<pll> q;
        q.push({nd,-1});
        while(!q.empty()){
            auto [curr, par] = q.front();
            q.pop();
            for(ll nxt: adj[curr]){
                if(nxt != par){
                    q.push({nxt, curr});
                    dist[nxt] = dist[curr]+1;
                }
            }
        }
    };

    bfs(1);
    ll mx_nd = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(n+1, 0);
    //oArray(dist, n+1);
    bfs(mx_nd);
    //oArray(dist, n+1);
    o1(*max_element(all(dist)));
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}