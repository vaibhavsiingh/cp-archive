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
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<ll> par(n+1,-1);

    auto bfs = [&](int nd){
        queue<ll> q;
        q.push(nd);
        par[nd] = 0;
       // cout << "bfs " << nd << endl;
        while(!q.empty()){
            ll curr = q.front();
            q.pop();

            //o2("loop over ", curr);
            for(ll nxt: adj[curr]){
              //  o2(nxt, par[nxt]);
                if(nxt == par[curr]){
                    continue;
                }                
                if(par[nxt] == -1){
                    // o1("YEs");
                    par[nxt] = curr;
                    q.push(nxt);
                }
                else{
                    return pair<ll,ll>({curr, nxt});
                }
            }
        }
        return pair<ll,ll>({-1,-1});
    };

    for(int nd=1; nd<=n; nd++){
        if(par[nd] == -1){
            auto [x,y] = bfs(nd);
            // o2(x,y);
            if(x==-1){
                continue;
            }
            vector<ll> par_list;
            ll copy_x = x;
            while(x!=0){
                par_list.push_back(x);
                x = par[x];
            }
          //  oArray(par_list, par_list.size());

            set<ll> all_nodes(all(par_list));
            ll common = y;
            ll found = false;;
            while(common!=0){
                if(all_nodes.count(common)){
                    found = true;
                    break;
                }
                common = par[common];
            }
            
            if(!found){
                o1("CHUTIA KATT GYA");
                continue;
            }
            found = false;
            vll path;
            for(ll i=par_list.size()-1; i>=0; i--){
                if(par_list[i] == common){
                    found = true;
                }
                if(found){
                    path.pb(par_list[i]);
                }
            }

            if(!found){
                o1("CHUTIA KATT GYA 2");
                continue;
            }

            
            while(y!=common){
                path.pb(y);
                y = par[y];
            }
            path.pb(common);
            o1(path.size());
            oArray(path, path.size());
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}