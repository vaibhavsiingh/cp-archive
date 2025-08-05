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

const ll MOD = 1000000007;

void sol(){
    ll n,a,b;
    cin >> n >> a >> b;
    if(abs(a-b)>1 || a+b+2>n){
        o1(-1);
        return;
    }
    vll ans;
    if(a>b){
        ll nums_req = a+b+2;
        
        ll small_start = n-a-b-1, large_start= n-a+1;
        ll large=0;
        for(int i=0; i<nums_req; i++){
            if(large){
                ans.pb(large_start++);
                large=0;
            }
            else{
                ans.pb(small_start++);
                large=1;
            }
            
        }
        large_start = n-a-b-2;
        while(ans.size()<n){
            ans.pb(large_start--);
        }
    }
    else if(a<b){
        ll nums_req = a+b+2;
        ll small_start = 1, large_start = b+1;
        ll large=1;
        for(int i=0; i<nums_req; i++){
            if(large){
                ans.pb(large_start++);
                large=0;
            }
            else{
                ans.pb(small_start++);
                large=1;
            }
            
        }
        while(ans.size()<n){
            ans.pb(large_start++);
        }
    }
    else{
        ll nums_req = a+b+2;
        ll small_start = 1, large_start = b+2;
        ll large=0;
        for(int i=0; i<nums_req; i++){
            if(large){
                ans.pb(large_start++);
                large=0;
            }
            else{
                ans.pb(small_start++);
                large=1;
            }
            
        }
        while(ans.size()<n){
            ans.pb(large_start++);
        }
    }
    oArray(ans,n);
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