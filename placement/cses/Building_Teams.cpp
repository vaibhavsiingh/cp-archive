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
    ll n,m;
    cin >> n >> m;

    vector<vll> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<ll> color(n+1,0);

    auto bfs = [&](ll nd){
        color[nd] = 1;
        queue<ll> q;
        q.push(nd);

        while(!q.empty()){
            ll curr = q.front();
            q.pop();

            for(ll nxt: adj[curr]){
                if(color[nxt] == color[curr]){
                    return false;
                }
                if(color[nxt] == 0){
                    if(color[curr] == 1) color[nxt] = 2;
                    else color[nxt] = 1;
                    q.push(nxt);
                }

            }
        }
        return true;
    };
    
    for(ll s=1; s<=n; s++){
        if(color[s] == 0){
            if(!bfs(s)){
                o1("IMPOSSIBLE");
                return;
            }            
        }
    }
    for(ll i = 0; i < n; i++) {
        cout << color[i+1] << ' ';  
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}