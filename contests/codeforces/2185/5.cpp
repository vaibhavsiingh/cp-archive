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
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n);
    vll s(m);
    iArray(a,n);
    iArray(s,m);
    sort(all(s));
    string str;
    cin >> str;
    map<ll,ll> mp;
    map<ll,vll> l2i, r2i;
    vll i2l(n), i2r(n);
    for(ll i = 0; i < n; i++) {
        auto itr = lower_bound(all(s),a[i]);
        if(itr != s.end() && *itr == a[i]){
            mp[0]++;
            continue;
        }
        ll l = -INF;
        if(itr!=s.begin()){
            itr--;
            l = -(a[i]-(*itr));
            mp[l]++;            
        }
        ll r= INF;
        itr = upper_bound(all(s),a[i]);
        if(itr!=s.end()){
            r = (*itr) - a[i];
            mp[r]++;            
        }

        if(l!=-INF && r!=INF) {
            l2i[l].pb(i);
            r2i[r].pb(i);
            i2l[i] = l;
            i2r[i] = r;
        }
    }
    ll dead = mp[0];
    mp[0] = 0;
    ll curr = 0;    
    for(ll i = 0; i < k; i++) {        
        if(str[i]=='L') curr--;
        else curr++;
        if(mp[curr]>0){
            dead += mp[curr];
            if(curr>0){
                for(ll idx: r2i[curr]){
                    mp[i2l[idx]]--;                    
                }
            }
            else{
                for(ll idx: l2i[curr]){
                    mp[i2r[idx]]--;                    
                }
            }
            mp[curr] = 0;
        }
        cout << n-dead << ' ';
    }
    o1("");

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