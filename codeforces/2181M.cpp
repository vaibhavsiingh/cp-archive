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
    string x,y;
    cin >> x >> y;
    ll n = x.length();
    vector<vll> dp(n+1, vll(2));
    dp[0][0] = 0;
    dp[0][1] =  INF;

    auto delta = [&](char a, char b){
        if(a==b) return 0;
        else return 1;
    };

    for(ll i=1; i<=n; i++){
        dp[i][0] = min(dp[i-1][0]+ delta(y[i-1],'0')+ delta(x[i-1],'0'), dp[i-1][1]+ delta(y[i-1],'0')+ delta(x[i-1],'1'));
        dp[i][1] = min(dp[i-1][0]+ delta(y[i-1],'1')+ delta(x[i-1],'1'), dp[i-1][1]+ delta(y[i-1],'1')+ delta(x[i-1],'0'));
    }
    o1(min(dp[n][0], dp[n][1]));
    
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