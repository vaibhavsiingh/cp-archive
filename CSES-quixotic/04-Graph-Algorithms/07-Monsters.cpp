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
vector<vll> vism;
vector<vll> visa;
vector<vector<pll>> parent;

void bfsm(queue<pll>& q){
    while(!q.empty()){
        ll curr_x = q.front().ff,curr_y = q.front().ss;
        q.pop();
        vector<pll> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        for(auto [dx,dy]:dir){
            ll nx = curr_x+dx, ny = curr_y+dy;
            if(nx <0 || ny<0 || nx>=n || ny>=m || v[nx][ny]=='#' || v[nx][ny]=='M') continue;
            if(vism[nx][ny]==-1 || vism[nx][ny]>vism[curr_x][curr_y]+1){
                vism[nx][ny] = vism[curr_x][curr_y]+1;
                q.push({nx,ny});
            }
        }
    }
}

pll bfsA(ll x, ll y){
    queue<pll> q;
    q.push({x,y});
    visa[x][y] = 0;
    while(!q.empty()){
        ll curr_x = q.front().ff,curr_y = q.front().ss;
        q.pop();
        if(curr_x == 0 || curr_y == 0 || curr_x == n-1 || curr_y == m-1){
            return {curr_x,curr_y};
        }
        vector<pll> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        for(auto [dx,dy]:dir){
            ll nx = curr_x+dx, ny = curr_y+dy;
            if(nx <0 || ny<0 || nx>=n || ny>=m || v[nx][ny]=='#') continue;
            if(visa[nx][ny]!=-1) continue;
            visa[nx][ny] = visa[curr_x][curr_y]+1;
            if(visa[nx][ny]>=vism[nx][ny] && vism[nx][ny]!=-1) continue;
            parent[nx][ny] = {curr_x,curr_y};
            q.push({nx,ny});
        }
    }
    return {-1,-1};
    
}

void sol(){
    cin >> n >> m;
    v.resize(n);
    vism = vector<vll>(n, vll(m,-1));
    visa = vector<vll>(n, vll(m,-1));
    parent = vector<vector<pll>>(n, vector<pll>(m));
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    queue<pll> q;
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<m; j++){
            if(v[i][j]=='M'){
                q.push({i,j});
                vism[i][j] = 0;
            }
        }
    }
    bfsm(q);
    // for(ll i = 0; i < n; i++) {
    //     for(ll j=0; j<m; j++){
    //         cout << vism[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << endl;
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<m; j++){
            if(v[i][j]=='A'){
                pll ans = bfsA(i,j);
                // for(ll i = 0; i < n; i++) {
                //     for(ll j=0; j<m; j++){
                //         cout << visa[i][j] << ' ';
                //     }
                //     cout << endl;
                // }
                if(ans.ff==-1) {
                    o1("NO");
                    return;
                }
                o1("YES");
                
                stack<char> path;
                //o2(ans.ff,ans.ss);
                while(ans.ff != i || ans.ss != j ){
                    if(ans.ff < parent[ans.ff][ans.ss].ff) path.push('U');
                    else if(ans.ff > parent[ans.ff][ans.ss].ff) path.push('D');
                    else if(ans.ss < parent[ans.ff][ans.ss].ss) path.push('L');
                    else path.push('R');
                    ans = parent[ans.ff][ans.ss];
                }
                o1(path.size());
                while(!path.empty()){
                    cout << path.top();
                    path.pop();
                }
                cout << "\n";
                return;
            }
            
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}