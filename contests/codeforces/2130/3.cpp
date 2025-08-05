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
    int n;
    cin >> n;
    unordered_map<int,vector<pair<int,int>>> adj;
    int x,y;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        adj[x].push_back({y,i+1});
        adj[y].push_back({x,i+1});
    }
    vector<int> ans;
    map<int,int> visited;
    

    for(auto [curr,_]:adj){
        if(!visited[curr]){
            queue<int> q;
            q.push(curr);
            visited[curr]=1;
            while(!q.empty()){
                int nd = q.front();
                q.pop();
                for(auto [nxt,idx]: adj[nd]){
                    if(!visited[nxt]){
                        ans.push_back(idx);
                        q.push(nxt);
                        visited[nxt] = 1;
                    }
                }
            }
        }
    }
    o1(ans.size());
    oArray(ans, ans.size());
    
    

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