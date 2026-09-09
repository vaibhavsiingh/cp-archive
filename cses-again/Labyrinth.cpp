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
    i2(n,m);

    vector<string> grid(n);
    for(ll i = 0; i < n; i++) {
        cin >> grid[i];
    }

    pair<ll,ll> start = {-1,-1}, end = {-1,-1};
    for(ll i = 0; i < n; i++) {        
        for(ll j=0; j<m; j++){
            if(grid[i][j] == 'A'){
                start = {i,j};                
            }            
            if(grid[i][j] == 'B'){
                end = {i,j};
            }
        }
        if(start.first != -1 && end.first != -1) break;
    }

    queue<pair<ll,ll>> q;
    q.push(start);
    vector<vector<char>> steps(n, vector<char>(m, '.'));
    steps[start.ff][start.ss] = '_';

    vector<pair<ll,ll>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};

    unordered_map<int, char> idx_to_dir;
    idx_to_dir[0] = 'D';
    idx_to_dir[1] = 'R';
    idx_to_dir[2] = 'U';
    idx_to_dir[3] = 'L';

    bool found = false;

    while(!q.empty() && !found){
        auto [x,y] = q.front();
        q.pop();

        for(ll di=0; di<4; di++){
            auto [dx,dy] = dir[di];
            ll nx = x+dx, ny = y+dy;
            if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]!='#'){
                
                if(steps[nx][ny] != '.'){
                    continue;
                }
                
                steps[nx][ny] = idx_to_dir[di];
                q.push({nx,ny});

                if(grid[nx][ny] == 'B'){
                    found = true;
                    break;
                }
                
            }
        }
        
    }

    // for(ll i = 0; i < n; i++) {
    //     for(ll j=0; j<m; j++){
    //         cout << steps[i][j];
    //     }
    //     cout << endl;

    // }

    if(steps[end.first][end.second] == '.'){
        cout << "NO\n";
        return;
    }

    string path;
    map<char, pair<pair<ll,ll>, char>> rev_dir;
    rev_dir['L'] = {{0,-1}, 'R'};
    rev_dir['R'] = {{0,1}, 'L'};
    rev_dir['U'] = {{-1,0}, 'D'};
    rev_dir['D'] = {{1,0}, 'U'};

    ll x = end.first, y = end.second;
    while(x != start.ff || y != start.ss){
        
        auto [pp, d] = rev_dir[steps[x][y]];
        auto [dx,dy] = pp;

        x += dx;
        y += dy;
        path.push_back(d);
    }
    o1("YES");
    o1(path.length());
    reverse(all(path));
    o1(path);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}