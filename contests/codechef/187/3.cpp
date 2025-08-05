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

const ll MOD = 998244353;

ll bin2dec(string s){
    int n = s.length();
    ll ans = 0;
    ll power = 0;
    for(int i=n-1; i>=0; i--){
        if(s[i]=='1') ans += (1<<power);
        power++;
    }
    return ans;
}

void sol(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n<4){
        o1(1);
        return;
    }
    
    vector<vll> dp(n,vll(8));
    string first3 = s.substr(0,3);
    ll x = bin2dec(first3);
    dp[2][x] = 1;
    for(int i=3; i<n; i++){
        if(s[i]=='0'){
            dp[i][0] = (dp[i-1][0]+dp[i-1][4])%MOD;
            dp[i][2] = (dp[i-1][1]+dp[i-1][5])%MOD;
            dp[i][4] = (dp[i-1][2]+dp[i-1][5]+dp[i-1][6])%MOD;
            dp[i][6] = (dp[i-1][3]+dp[i-1][7])%MOD;
            dp[i][1] = 0;
            dp[i][3] = 0;
            dp[i][5] = 0;
            dp[i][7] = 0;
        }
        else{
            dp[i][1] = (dp[i-1][0]+dp[i-1][4])%MOD;
            dp[i][3] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][5])%MOD;
            dp[i][5] = (dp[i-1][2]+dp[i-1][6])%MOD;
            dp[i][7] = (dp[i-1][3]+dp[i-1][7])%MOD;
            dp[i][2] = 0;
            dp[i][4] = 0;
            dp[i][6] = 0;
            dp[i][0] = 0;
        }
    }
    ll ans=0;
    for(ll i=0; i<8;i++){
        ans = (ans+dp[n-1][i])%MOD;
    }
    o1(ans);
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
}