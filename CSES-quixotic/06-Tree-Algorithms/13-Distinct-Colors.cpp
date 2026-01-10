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

vector<vll> adj;
vll color;
vector<set<ll>> vs;
vll ans;


void recurse(ll nd, ll p){
    for(ll c: adj[nd]){
        if(c!=p){
            recurse(c,nd);
            if(vs[nd].size()<vs[c].size()) swap(vs[nd],vs[c]);
            for(ll col: vs[c]) vs[nd].insert(col);
        }
    }
    ans[nd-1] = vs[nd].size();
}

void sol(){
    ll n;
    cin >> n;
    color.resize(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> color[i+1];
    }

    adj.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vs.resize(n+1);
    for(ll i = 0; i < n; i++) {
        vs[i+1].insert(color[i+1]);
    }

    ans.resize(n+1);
    recurse(1,0);
    oArray(ans,n);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}