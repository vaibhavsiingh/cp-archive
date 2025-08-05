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
#define ivec(a) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;
#define ovec(a) for(ll i=0; i<a.size(); i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

void sol(){
    ll n,t;
    i2(n,t);
    vll a(n);
    ivec(a);
    
    ll mx = t*(*min_element(a.begin(),a.end()));
    ll mn = 0;
    
    while(mn < mx){
        ll time = (mn+mx)/2;
        ll total_machines = 0;
        for(ll i = 0; i < n; i++) {
           total_machines += (time/a[i]);
        }
        if(total_machines>=t){
            mx = time;
        }
        else{
            mn = time+1;
        }
    }
    o1(mn);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}