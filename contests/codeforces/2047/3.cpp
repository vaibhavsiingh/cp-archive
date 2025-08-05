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
    int n;
    cin >> n;
    vll a(n),b(n);
    iArray(a,n);
    iArray(b,n);
    int base_sum = 0;
    for(int i=0; i<n; i++){
        base_sum += (a[i]>b[i]) ? a[i] : b[i];
    }
    ll max_sec = -1e6;
    for(int i=0; i<n; i++){
        if(a[i]>b[i]) {
            max_sec = max(max_sec,b[i]);
        }
        else max_sec = max(max_sec,a[i]);
    }
    o1(base_sum+max_sec);
    
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