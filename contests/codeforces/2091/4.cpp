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
    ll n ;
    cin >> n;
    string s;
    cin >> s;
    ll cnt = 0;
    ll mx_cnt = 0;
    ll lst_o = 0;
    for(ll i=0; i<n; i++){
        if(s[i]=='(' ) cnt++, lst_o = i;
        else cnt--;
        mx_cnt = max(mx_cnt, cnt);
    }
    if(mx_cnt == n/2 ){
        o1(-1);
        return;
    }
    if(mx_cnt==n/2-1 && s[n-2]=='('){
        o1(-1);
        return;
    }
    for(ll i=0; i<n; i++){
        if(s[i]==')'){
            ll fnd = 0;
            for(ll j=i+1; j<lst_o; j++){
                if(s[j]=='(') {
                    fnd++;
                    break;
                }
            }
            if(fnd) {
                o1(n-2);
                return;
            }
            else {
                o1(-1);
                return;
            }
        }
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