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
    ll n,k;
    cin >> n >> k;

    ll UNDERROOT_N = sqrt(n) + 1;
    vector<vector<ll>> grid(UNDERROOT_N+1);

    ll num = 1;
    for(ll i=0; i<=UNDERROOT_N && num <= n; i++){
        for(ll j=0; j<UNDERROOT_N && num <= n; j++){
            grid[i].push_back(num++);
        }
    }

    ll cnt = 0;
    ll i=0,j=0;
    
    while(cnt < n){        
        ll aage = grid[i].size() - j;
        ll curr_k = k % (n-cnt);
       // o2(aage,curr_k);
        while(aage <= curr_k){
            j = 0;
            curr_k-=aage;
            if (++i == UNDERROOT_N) i = 0;
            aage = grid[i].size();
      //      o2(aage,curr_k);
        }
     //   o1("done");
    //    o2(i,j);
        j += curr_k;
        if(j>grid[i].size()){
            o1("lode lg gaye");
            return;
        }
        cout << (grid[i][j]) << ' ';
        cnt++;
        grid[i].erase(grid[i].begin() + j);        
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}