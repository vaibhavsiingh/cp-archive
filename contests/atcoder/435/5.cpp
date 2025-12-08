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
    ll n,q;
    i2(n,q);

    set<pll> s;
    s.insert({n,1});
    ll ans = n;
    while(q--){
        ll L,R;
        i2(L,R);
      
        auto i0 = s.lower_bound({L,-1});                
        vector<pll> to_add;        
        for(auto itr=i0; itr!=s.end(); ){
            ll l=itr->second, r = itr->first;            
            if(l>R) break;
            if(L<=l && r<= R){
                ans -= r-l+1;
            }
            else if(l<L && r<=R){
                ans -= r-L+1;
                to_add.pb({L-1,l});
            }
            else if(L<=l && R<r){
                ans -= R-l+1;
                to_add.pb({r,R+1});
            }
            else if(l<L && R<r){
                ans -= R-L+1;
                to_add.pb({r,R+1});
                to_add.pb({L-1,l});
            }            
            itr = s.erase(itr);
        }
                
        for(auto x : to_add) s.insert(x);
        
        o1(ans);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}