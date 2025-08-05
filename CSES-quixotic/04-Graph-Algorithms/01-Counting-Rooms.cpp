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

const ll MOD = 1000000007;


ll n,m;
vector<string> v;
vector<vll> visited;
ll ans = 0;

void dfs(int x, int y){
    if(visited[x][y]) return;
    visited[x][y] = 1;
    vector<pll> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    for(auto [dx,dy]: dir){
        ll nx = x+dx, ny = y+dy;
        if(nx>=n || nx<0 || ny>=m || ny <0 || v[nx][ny] == '#' ){
            continue;
        }
        dfs(nx,ny);
    }
    return;
}

void sol(){
    cin >> n >> m;
    v.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
        //cout << v[i] << endl;
    }
    visited = vector<vll>(n, vll(m, 0));
    for(int i=0; i<n; i++){
        for(ll j=0; j<m; j++){
            if(v[i][j]=='.' && visited[i][j]==0){
              //  reach;
                ans++;
                dfs(i,j);
            }
        }
    }
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}