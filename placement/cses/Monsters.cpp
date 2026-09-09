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
    vector<string> grid(n);
    for(ll i = 0; i < n; i++) {
        cin >> grid[i];
    }
    queue<pll> q;
    pll start;
    vector<vector<ll>> m_map(n, vll(m,INF));
    // reach;
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<m; j++){
            if(grid[i][j] == 'M'){
                q.push({i,j});
                m_map[i][j] = 0;
            }
            else if(grid[i][j]=='A'){
                start = {i,j};
            }
        }
    }
    if(start.ff==0 || start.ss==0 || start.ff == n-1 || start.ss == m-1){
        o1("YES");
        o1(0);
        return;
    }
    // reach;
    vector<pll> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(auto [dx,dy] : dir){
            ll nx = x+dx, ny = y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && m_map[nx][ny] == INF){
                m_map[nx][ny] = m_map[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    // reach;
    assert(q.empty());
    
    vector<vector<pll>> par(n, vector<pll>(m, {-4,-4}));
    vector<vll> A_map(n, vll(m,-1));

    q.push(start);
    par[start.ff][start.ss] = {0,0};
    A_map[start.ff][start.ss] = 0;

    // unordered_map<ll, char> idx2char;
    // idx2char[0] = 'D';
    // idx2char[1] = 'R';
    // idx2char[2] = 'U';
    // idx2char[3] = 'L';

    pair<ll,ll> reached = {-1,-1};
    // reach;
    while(!q.empty() && reached.ff == -1) {
        auto [x,y] = q.front();
        q.pop();
        ll curr_time = A_map[x][y];
        for(ll i=0; i<4; i++){
            auto [dx,dy] = dir[i];
            ll nx = x+dx, ny = y+dy;
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && m_map[nx][ny] > curr_time+1 && par[nx][ny].ff == -4){
                A_map[nx][ny] = curr_time+1;
                q.push({nx,ny});
                par[nx][ny] = {-dx,-dy};
                if(nx==0 || ny==0 || nx == n-1 || ny == m-1){
                    reached = {nx,ny};
                    break;
                }
            }
        }
    }
    // reach;
    
    if(reached.ff == -1){
        o1("NO");
        return;
    }
    o1("YES");
    vector<char> path;
    // reach;
    
    while(reached != start){
        
        pll dir_change = par[reached.ff][reached.ss];
        reached.ff += dir_change.ff;
        reached.ss += dir_change.ss;
    //    o2(reached.ff, reached.ss);
        if(dir_change.ff == 1){
            path.push_back('U');
        }
        else if(dir_change.ff == -1){
            path.push_back('D');
        }
        else if(dir_change.ss == 1){
            path.push_back('L');
        }
        else{
            path.push_back('R');
        }
        
    }
    // reach;
    o1(path.size());
    reverse(all(path));
    for(ll i = 0; i < path.size(); i++) {
        cout << path[i];
    }
    // reach;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}