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
    ll n, m;
    cin >> n >> m;
    vector<vll> adj(n+1);

    for(ll i = 0; i < m; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vector<int> color(n+1, -1);
    
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(color[i] != -1){
            continue;
        }

        color[i] = 0;
        queue<int> q;
        q.push(i);
        int col0 = 1;
        int col1 = 0;
        bool oddCycle = false;

        while(!q.empty()){
            int nd = q.front();
            q.pop();

            for(auto nxt: adj[nd]){
                if(color[nxt] == color[nd]){
                    oddCycle = true;                    
                }
                if(color[nxt] != -1){
                    continue;
                }
                color[nxt] = (color[nd]+1)%2;
                q.push(nxt);
                if(color[nxt] == 0) col0++;
                else col1++;
            }
        }
        //o2(i, num);
        if(!oddCycle){
            ans += max(col1, col0);
        }        
    }
    o1(ans);

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