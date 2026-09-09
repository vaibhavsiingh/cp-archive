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
    ll n;
    cin >> n;

    vector<vll> adj(n+1);

    bool no = false;
    for(ll i = 0; i < n; i++) {
        ll x,y;
        cin >> x >> y;
        if(x==y){
            no = true;
        }
        adj[x].push_back(y);
        adj[y].push_back(x);        
    }

    if(no){
        o1("NO");
        return;
    }

    for(int i=1; i<=n; i++){
        if(adj[i].size() != 2){
            o1("NO");
            return;
        }
    }

    vll vis(n+1);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            ll par = i;
            ll nd = adj[i][0];
            ll s = 1;
            vis[i] = 1;
            while(nd!=i){
                vis[nd] = 1;
                ll curr = nd;
                if(adj[nd][0] == par){
                    nd = adj[nd][1];
                }
                else{
                    nd = adj[nd][0];
                }
                par = curr;
                s++;
            }
            if(s%2!=0){
                o1("NO");
                return;
            }
        }
    }
    o1("YES");
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