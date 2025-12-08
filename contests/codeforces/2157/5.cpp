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
    vll a(n);
    iArray(a,n);

    unordered_map<ll,ll> m;
    for(ll i = 0; i < n; i++) {
        m[a[i]]++;
    }    
    ll ans=0;
    stack<ll> stk;
    for(ll lvl=3*n; lvl>2*n; lvl--){
        stk.push(lvl);
    }
    for(ll lvl=2*n; lvl>=1; lvl--){
        if(m[lvl]<=k) stk.push(lvl);
        else{
            ll steps = 0;            
            ll curr = m[lvl];         
            ll curr_lvl = lvl;   
            while(curr>k){    
                m[curr_lvl] = 1;            
                ll x = stk.top();
                stk.pop();
                curr = curr + m[x] -1;
                steps += x - curr_lvl;
                curr_lvl = x;
            }            
            m[curr_lvl] = k;
            stk.push(curr_lvl);
            ans = max(steps,ans);
        }
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
    return 0;
}