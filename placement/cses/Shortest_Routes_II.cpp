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
    ll n,m,q;
    cin >> n >> m >> q;
    
    //vector<vector<pll>> adj(n+1);
    vector<vector<ll>> dist(n+1, vll(n+1, INF));

    for(ll i=1; i<=n; i++) dist[i][i] = 0;
    for(ll i = 0; i < m; i++) {
        ll x,y,c;
        cin >> x >> y >> c;
        dist[x][y] = min(dist[x][y], c);
        dist[y][x] = min(dist[x][y], c);
    }

    for(ll k=1; k<=n; k++){
        for(ll i=1; i<=n; i++){
            for(ll j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while(q--){
        ll a,b;
        cin >> a >> b;
        if(dist[a][b] ==  INF){
            o1(-1);
        }
        else{
            o1(dist[a][b]);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}