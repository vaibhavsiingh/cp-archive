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
    unordered_map<ll,ll> m_bass, m_pitch;
    vector<vll> edge_idx_mp(2*n+1,vll(2*n+1));
    vll deg(2*n+1);
    ll x,y;
    ll idx_bass=1,idx_pitch=n+1;
    vector<vll> adj(2*n+1);
    for(ll i = 0; i < n; i++) {
        i2(x,y);
        if(m_bass[x]==0) m_bass[x]= idx_bass++;
        if(m_pitch[y]==0) m_pitch[y]= idx_pitch++;
        ll bi=m_bass[x], pi=m_pitch[y];
        deg[bi]++;
        deg[pi]++;
        edge_idx_mp[bi][pi] = i+1;
        edge_idx_mp[pi][bi] = i+1;
        adj[bi].pb(pi);
        adj[pi].pb(bi);
    }

    ll v1=0,v2=0, bad=0;
    for(ll i=1; i<=idx_bass; i++){
        ll d = deg[i];
        if(d&1){
            if(v1==0){
                v1 = i;
            }
            else if(v2==0){
                v2 = i;
            }
            else{
                bad=1;
                break;
            }
        }
        if(d==0){
            bad=1;
            break;
        }
    }
    for(ll i=n+1; i<=idx_pitch; i++){
        ll d = deg[i];
        if(d&1){
            if(v1==0){
                v1 = i;
            }
            else if(v2==0){
                v2 = i;
            }
            else{
                bad=1;
                break;
            }
        }
        if(d==0){
            bad=1;
            break;
        }
    }

    if(v1!=0 && v2==0) bad = 1;

    if(bad){
        o1("NO");
        return;
    }

    if(v1!=0){
        adj[v1].pb(v2);
        adj[v2].pb(v1);
    }

    ll first = 1;

    stack<ll> stk;
    stk.push(first);
    vll res;
    while(!stk.empty()){
        ll x = stk.top();
        ll added = 0;
        if(adj[x].size()!=0){
               
        }
        if(!added){
            stk.pop();
            res.pb(x);
        }
    }
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