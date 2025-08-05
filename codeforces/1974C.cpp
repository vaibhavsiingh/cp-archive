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

const ll MOD = 1000000007;

void sol(){
    ll n;
    cin >> n;
    ll a[n];
    iArray(a,n);
    multimap<pair<ll,ll>,ll> m;
    int count=0;
    for(ll i=0; i<n-1; i++){
        if(m.find({a[i],a[i+1]})!=m.end()){
            auto lwr = m.lower_bound({a[i],a[i+1]});
            auto upr = m.upper_bound({a[i],a[i+1]});
            while(lwr != upr){
                int idx =  lwr->second;
                if(idx > 0 ){
                    if(a[idx -1]!=a[i-1]) {count++;
                    }
                    
                }
                if(i <n-2){
                   
                    if(a[idx+2]!=a[i+2]){
                         count++;
                          //o2(idx,i);
                    }
                }
                lwr++;
            }         
        }
        m.insert({{a[i],a[i+1]},i});
    }
    multimap<pair<ll,ll>,ll> m2;
    for(ll i=0; i<n-2; i++){
        if(m2.find({a[i],a[i+2]})!=m2.end()){
            auto lwr = m2.lower_bound({a[i],a[i+2]});
            auto upr = m2.upper_bound({a[i],a[i+2]});
            while(lwr!=upr){
                int idx= lwr->second;
                
                if(a[idx+1]!=a[i+1])
                {
                   // o2(idx,i);
                 count++;
                }
                lwr++;
            }
        }
        
        m2.insert({{a[i],a[i+2]},i});
    }
    // for(auto itr = m2.begin(); itr!=m2.end(); itr++){
    //     cout << itr->second << ' ';
    // }

    cout << count << endl;


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