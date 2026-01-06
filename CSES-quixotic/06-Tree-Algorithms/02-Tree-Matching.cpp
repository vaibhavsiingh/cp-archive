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

vector<vll> dp;
vector<vll> cldn;

void recurse(ll nd, ll par){
    ll withnd = 0, withoutnd = 0;    
    for(ll c:cldn[nd]){
        if(c!=par){
            recurse(c, nd);
            withoutnd += max(dp[c][0], dp[c][1]);            
        }
    }
    for(ll c:cldn[nd]){
        if(c!=par){
            withnd = max(withnd, withoutnd - max(dp[c][0], dp[c][1]) + dp[c][0] + 1);            
        }
    }
    dp[nd][0] = withoutnd;
    dp[nd][1] = withnd;   
}

void sol(){
    ll n;
    cin >> n;
    cldn.resize(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        cin >> x >> y;
        cldn[x].pb(y);
        cldn[y].pb(x);
    }
    dp.resize(n+1, vll(2));
    recurse(1,0);
    o1(max(dp[1][0], dp[1][1]));
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}