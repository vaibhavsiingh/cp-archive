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
    vll deg(n+1);
    vector<pair<int,int>> edges(n-1);
    for(int i=0; i<n-1; i++){
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
        deg[x]++;
        deg[y]++;
        edges[i] = {x,y};
    }
    for(int i=1; i<=n; i++){
        if(deg[i]==2){
            int x = adj[i][0], y = adj[i][1];
            o1("YES");
            vll outgoing(n+1);
            outgoing[x]=-1;
            queue<pair<int,int>> q;
            q.push({x,i});
            while(!q.empty()){
                auto [nx,ny] = q.front();
                q.pop();
                for(auto nd:adj[nx]){
                    if(nd!=ny){
                        if(outgoing[nd]==0){
                            outgoing[nd] = -1*outgoing[nx];
                            q.push({nd,nx});
                        }
                    }
                }
            }
            outgoing[y]=1;
            while(!q.empty())q.pop();
            q.push({y,i});
            while(!q.empty()){
                auto [nx,ny] = q.front();
                q.pop();
                for(auto nd:adj[nx]){
                    if(nd!=ny){
                        if(outgoing[nd]==0){
                            outgoing[nd] = -1*outgoing[nx];
                            q.push({nd,nx});
                        }
                    }
                }
            }
       //     oArray(outgoing, n+1);
            o2(i,x);
            o2(y,i);
            for(auto [nx,ny]:edges){
                if((nx==i || ny==i)){
                    continue;
                }
                else{
                    if(outgoing[nx]==1){
                        o2(nx,ny);
                    }
                    else o2(ny,nx);
                }
            }
            return;
        }        
    }
    o1("NO");
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