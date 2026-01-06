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
    ll n,nq;
    cin >> n >> nq; 
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<vll> par(n+1, vll(18));
    vll level(n+1);
    queue<pll> q;
    q.push({1,0});
    while(!q.empty()){
        auto [nd,p] = q.front();
        q.pop();
        par[nd][0] = p;  
        level[nd] = level[p]+1;      
        for(auto c: adj[nd]){
            if(c!=p){
                q.push({c,nd});
            }
        }
    }

    for(ll i=1; i<18; i++){
        for(ll nd=1; nd<=n; nd++){
            par[nd][i] = par[par[nd][i-1]][i-1];
        }
    }
    
    while(nq--){
        ll nd1,nd2;
        i2(nd1,nd2);
        ll ans  = 0;
        if(level[nd1]>level[nd2]) swap(nd1,nd2);
        if(level[nd1]!=level[nd2]){
            ll stp = 17;
            while(stp>=0){
                ll nm = (1<<stp);
                if(level[nd2]-nm >= level[nd1]){
                    ans += nm;
                    
                    nd2 = par[nd2][stp];
                }
                stp--;
            }
        }
        if(nd1==nd2) o1(ans);
        else{
            ll stp = 17;
            while(stp>=0){
                ll nm = (1<<stp);
                if(par[nd1][stp]!=par[nd2][stp]){
                    ans += 2*nm;
                    nd1 = par[nd1][stp];
                    nd2 = par[nd2][stp];                    
                }
                stp--;
            }
            ans+=2;
            o1(ans);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}