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
    ll n;
    cin >> n;
    ll sm  = (n*(n+1))/2;
    if(sm%2==1){
        o1("NO");
        return;
    }
    vll vis(n+1,0);
    ll req_sm = sm/2;
    ll curr_sm = 0;
    ll mx = n;
    vll set1,set2;
    while(curr_sm < req_sm){
        if(mx+curr_sm>=req_sm){
            set1.pb(req_sm-curr_sm);
            vis[req_sm-curr_sm]++;
            curr_sm = req_sm;
        }
        else{
            curr_sm+=mx;
            vis[mx]++;
            set1.pb(mx);
            mx--;
        }
    }
    o1("YES");
    o1(set1.size());
    oArray(set1, set1.size());
    o1(n-set1.size());
    for(ll i = 1; i <= n; i++) {
        if(vis[i]!=1){
            cout << i << ' ';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}