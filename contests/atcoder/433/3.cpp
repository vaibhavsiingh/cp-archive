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
    string s;
    cin >> s;
    vector<pair<ll,ll>> v;
    ll n = s.length();
    
    for(ll i = 0; i < n; i++) {
        ll len = 1;
        for(ll j=i+1; j<n;){
            if(s[j]==s[i]) j++, len++;
            else break;
        }
        v.push_back({s[i]-'0',len});
        i+=len-1;
    }
    ll ans = 0;
    for(ll x=0; x<v.size()-1; x++){
        if(v[x].first+1 == v[x+1].first) ans += min(v[x].second,v[x+1].second);
    }
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}