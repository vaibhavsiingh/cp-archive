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
    ll n,m;
    i2(n,m);

    vector<string> grid(n);
    for(ll i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<vector<int>> vis(n, vector<int>(m,0));

    auto bfs = [&](int x, int y){
        queue<pair<int,int>> q;
        vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};

        q.push({x,y});
        vis[x][y] = 1;

        while(!q.empty()){
            auto [cx,cy] = q.front();
            q.pop();
            for(auto [dx,dy]: dir){
                int nx = cx+dx, ny = cy+dy;
                if(nx>=0 && nx < n && ny >=0 && ny<m && grid[nx][ny] == '.' && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    };

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == '.' && vis[i][j]==0){
                bfs(i,j);
                cnt++;
            }
        }
    }
    o1(cnt);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}