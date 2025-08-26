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
    ll n;
    cin >> n;
    vector<vector<ll>> club(n+1);
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        cout << "? " << i << ' '  << n << ' ';
        for(ll j=1; j<=n; j++) cout << j << ' ';
        cout <<'\n';
        cout.flush();
        ll ret;
        cin >> ret;
        if(ret==-1) return;
        club[ret].push_back(i);
        ans = max(ans, ret);
    }

    vector<ll> path;
    path.push_back(club[ans][0]);
    vector<ll> all_nums(n+1,1);    
    ll curr = ans;
    ll count = n;
    for(ll x: club[ans]) all_nums[x]=0, count--;
    ll curr_nd = path.back();
    while((--curr)>0){        
        for(ll x: club[curr]) all_nums[x]=0, count--;
        for(ll y: club[curr]){
            cout << "? " << curr_nd << ' '  << count+2 <<' ' << y << ' ' << curr_nd << ' ';
            for(ll j=1; j<=n; j++)if(all_nums[j]) cout << j << ' ';   
            cout << '\n';
            cout.flush();
            ll ret;
            cin >> ret;
            if(ret==-1) return;
            if(ret==curr+1) {
                path.push_back(y);
                curr_nd=y;
                break;
            }
        }
    }

    cout << "! "  << ans<< ' ';
    for(ll j:path) cout << j << ' ';
    cout <<'\n'; 
    cout.flush();   

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}