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
    ll n,k;
    i2(n,k);

    string s;
    cin >> s;

    string s1;
    ll curr = (s[(k-1)%n]=='1') ? 1 : 0;
    
    for(ll i = k%n; i != k-1; i=(i+1)%n) {
        s1.push_back(s[i]);        
    }

    ll l=0, r=n-2;
    n--;    
    vector<vector<pll>> dp(n,vector<pll>(n));
    vector<vector<pll>> dp2(n,vector<pll>(n));
    for(ll i = 0; i < n; i++) {
        ll temp = s1[i]-'0';
        dp[i][i] = {temp, -temp};
    }

    for(ll j=1; j<n; j++){
        for(ll i=0; i+j<n; i++){
            ll temp = s1[i]-'0';
            ll temp2 = s1[i+j]-'0';
            ll x1 = temp+dp[i+1][i+j].second;
            ll x2 = dp[i][i+j-1].second+temp2;
            ll y1 = -temp+dp[i+1][i+j].first;
            ll y2 = dp[i][i+j-1].first-temp2;

            if(x1<=0) x1 = -INF;
            if(x2<=0) x2 = -INF;
            if(y2<=0) y2 = -INF;
            if(y1<=0) y1 = -INF;
            dp[i][i+j] = {
                max(x1, x2),
                max(y1, y2)
            };
            if(x1>x2){
                dp2[i][j].first = i;
            }
            else{
                dp2[i][j].first = i+j;
            }
            if(y1>y2){
                dp2[i][j].second = i;
            }
            else{
                dp2[i][j].second = i+j;
            }
        }
    }

    if(dp[0][n-1].second<0){
        o1(-1);
    }
    else{
        ll i=0, j=n-1;
        vll seq;
        seq.push_back(k);
        while(i<j){
            seq.push_back((k+dp2[i][j].second)%(n+1)+1);
            if(dp2[i][j].first==i) i++;
            j--;
            if(i<j){
                seq.push_back((k+dp2[i][j].first)%(n+1)+1);
                if(dp2[i][j].second==i) i++;
                j--;
            }
        }
        // seq.push_back((k+i)%(n+1)+1);
        vll temp(n+1);
        for(ll i = 0; i < seq.size(); i++) {
            temp[seq[i]]++;
        }
        for(ll i = 1; i <= n; i++) {
            if(temp[i]==0){
                seq.push_back(i);
                break;
            }
        }
        oArray(seq, seq.size());
    }


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