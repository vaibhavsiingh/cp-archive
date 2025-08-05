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
    int n;
    cin >> n;
    vll a(n),b(n);
    iArray(a,n); iArray(b,n);
    vll x(n), y(n);
    for(int i=0; i<n; i++){
        if(i%2){
            x[i] = b[i];
            y[i] = a[i];
        }
        else{
            x[i] = a[i];
            y[i] = b[i];
        }
    }
   // oArray(x,n);
    //oArray(y,n);
    set<ll> s1,s2;
    ll ans=0;
    for(ll i=n-1; i>=0; i--){
        if(x[i]==y[i]) {
            ans = i+1;
            break;
        }
        if( s2.count(x[i]) || s1.count(y[i]) ){
            ans = i+1;
            break;
        }
        s1.insert(x[i]);
        s2.insert(y[i]);
    }
    set<ll> s;
    s.insert(x[n-1]);
    s.insert(y[n-1]);
    for(ll i=n-2; i>0; i--){
        if(s.count(x[i-1])|| s.count(y[i-1])){
            ans = max(ans,i);
            break;
        }
        s.insert(x[i]);
        s.insert(y[i]);
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