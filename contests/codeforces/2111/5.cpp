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
    ll n,q;
    i2(n,q);
    string s;
    cin >> s;
    unordered_map<char,unordered_map<char,ll>> m;
    vector<pair<char,char>> v;
    for(ll i = 0; i < q; i++)         
    {
        char x,y;
        i2(x,y);
        if(x=='a')   continue;
        v.pb({x,y});
    }
    for(ll i = q-1; i >= 0; i--) {
        auto [x,y] = v[i];
        m[x][y]++;
        if(y!='a'){            
            if(m[y]['a']>m[x]['d']) {
                m[x]['d']++;
            }
        }
    }
    ll idx=0;
    vll done(q);
    for(ll i = 0; i < n; i++) {
        if(s[i]=='a') continue;
        char curr = s[idx];
        char other = (curr=='b') ? 'c' : 'b';
        
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