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
vector<vector<pll>> parent;

void bfs(ll x, ll y, ll endx, ll endy){
    queue<pll> q;
    q.push({x,y});
    visited[x][y] = 1;
    while(!q.empty()){
        pll curr = q.front();
        ll curr_x = curr.first;
        ll curr_y = curr.second;
        q.pop();
        if(curr_x==endx && curr_y==endy){
            return;
        }
        vector<pll> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        for(auto [dx,dy]: dir){
            ll nx = curr_x+dx, ny = curr_y+dy;
            if(nx>=n || nx<0 || ny>=m || ny <0 || v[nx][ny] == '#' || visited[nx][ny] ){
                continue;
            }
            q.push({nx,ny});
            visited[nx][ny] = 1;
            parent[nx][ny] = {curr_x, curr_y};
        }

    }
}

void sol(){
    cin >> n >> m;
    v.resize(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    visited = vector<vll>(n, vll(m, 0));
    parent = vector<vector<pll>>(n, vector<pll>(m));
    ll startx, starty,endx,endy;
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<m; j++){
            if(v[i][j]=='A'){
                startx = i;
                starty = j;
            }
            else if(v[i][j]=='B'){
                endx = i;
                endy = j;
            }
        }
    }
    bfs(startx, starty, endx, endy);
    if(!visited[endx][endy]){
        o1("NO");
        return;
    }
    o1("YES");
    stack<char> path;
    ll currx = endx, curry = endy;
    // for(ll i = 0; i < n; i++) {
    //     for(ll j=0; j<m; j++){
    //         cout << i << ' ' <<j <<' ' << parent[i][j].ff << ' ' << parent[i][j].ss << endl;
    //     }
    // }
    while(currx != startx || curry != starty){
        ll parx = parent[currx][curry].ff;
        ll pary = parent[currx][curry].ss;
        if(parx<currx){
            path.push('D');
        }
        else if(parx>currx){
            path.push('U');
        }
        else if(pary>curry){
            path.push('L');
        }
        else path.push('R');
        currx = parx;
        curry = pary;
    }
    ll k = path.size();
    o1(k);
    for(ll i = 0; i < k; i++) {
        cout << path.top();
        path.pop();
    }
    cout << "\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}