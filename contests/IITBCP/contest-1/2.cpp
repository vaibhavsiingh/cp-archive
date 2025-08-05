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
    string s;
    cin >> s;
    int  n =s.length();
    vll count(n);
    count[n-1] = (s[n-1]==')');
    for(int i=n-2; i>=0; i--){
        count[i] = (s[i]==')') + count[i+1];
    }
    vll ans;
  //  oArray(count,n);
    for(int i=0; i<n; i++){
        if(s[i]=='('){
            if(count[i]>=ans.size()+1){
                ans.push_back(i);
            }
            else break;
        }
    }
    if(ans.size()==0){
        o1(0);
        return;
    }
    
    o1(1);
    o1(2*ans.size());
    for(ll i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << ' ';
    }
    int cnt=ans.size();
    ans.clear();
    for(int i=n-1; (i>=0 && cnt>0); i--){
        if(s[i]==')'){
            ans.pb(i);
            cnt--;
        }
    }
    reverse(all(ans));
    for(ll i = 0; i < ans.size(); i++) {
        cout << ans[i]+1 << ' ';
    }
    o1("");

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    return 0;
}