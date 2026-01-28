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
#define o2(a, b) cout << a << ' ' << b << "\n"
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
    ll n, k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    vector<vll> to_go(n);
    vector<vector<ll>> c_positions(26);
    for(ll i=0; i<n; i++){
        c_positions[s[i]-'a'].pb(i);
    }
    ll ptr=n;
    for(ll i=n-1; i>=0; i--){
        ll c = t[i]-'a';
        while(!c_positions[c].empty() && (c_positions[c].back()>ptr || c_positions[c].back()>i)) c_positions[c].pop_back();
        if(c_positions[c].empty()) {
            o1(-1);
            return;
        }
        ptr = c_positions[c].back();
        
        if(c_positions[c].back()!=i) to_go[c_positions[c].back()].pb(i);
    }
    ll n_steps  = 0;

    
    vector<ll> val(n), new_val;
    for(ll i=0; i<n; i++) val[i] = i;
    new_val = val;
    bool done = true;
    vector<bool> front(n), new_front(n,false);
    for(ll i=0; i<n; i++){
        done = done && to_go[val[i]].empty();
        front[i] = (!to_go[val[i]].empty());
    }
    
    vector<vll> ans;
    
    while(n_steps<k && !done){
        done = true;        
    //    oArray(val,n);
      //  oArray(front, n);
        for(ll i=0; i<n-1; i++){                                
            if(!front[i] || to_go[val[i]].empty()) continue;
            new_val[i+1] = val[i];            
            new_front[i+1] = true;
         
         
            if(to_go[val[i]].back()==i+1) to_go[val[i]].pop_back();
            done = done && to_go[val[i]].empty();
        }
        ans.pb(new_val);
        val = new_val;
        front = new_front;
        for(ll i = 0; i < n; i++) {
            new_front[i] = false;
        }
        n_steps++;
    }
    if(!done) o1(-1);
    else {
        o1(ans.size());        
        for(auto v: ans){
            string oo;
            for(ll i = 0; i < n; i++) {
                oo.pb(s[v[i]]);
            }
            o1(oo);
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