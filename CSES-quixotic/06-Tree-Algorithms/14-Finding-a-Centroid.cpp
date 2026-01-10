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
vector<vll> nmNd;
ll ans = -1;
ll n;

ll findNumNd(ll nd, ll p){
    ll sm = 1;
    for(ll i=0; i<adj[nd].size(); i++){
        ll c = adj[nd][i];
        if(c!=p){
            nmNd[nd][i] = findNumNd(c,nd);
            sm += nmNd[nd][i];
        }
    }
    return sm;
}

void findCentroid(ll nd, ll p, ll nm){
    ll sm = nm+1;
    ll allSet = 1;
    ll prob = -1;
    for(ll i=0; i<adj[nd].size(); i++){
        ll c = adj[nd][i];
        if(c!=p){
            if(nmNd[nd][i]>(n/2)) allSet = 0, prob = c;
            else sm += nmNd[nd][i];
        }
    }
    if(allSet) ans = nd;
    else{
        findCentroid(prob, nd, sm);
    }
}

void sol(){
    cin >> n;

    adj.resize(n+1);
    nmNd.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
        nmNd[x].pb(0);
        nmNd[y].pb(0);
    }

    findNumNd(1,0);
    findCentroid(1,0,0);
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}