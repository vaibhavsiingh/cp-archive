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
    ll n,x,y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vll a(n);
    iArray(a,n);

    if(x+y < accumulate(all(a),0ll)){
            o1("NO");
            return;
        }

    bool all_same = true;
    for(ll i=1; i<n; i++) {
        if(s[i]!=s[0]){
            all_same = false;
            break;
        }
    }

    if(all_same){
        if(s[0]=='1') swap(x,y); 
        ll x_need = 0;
        for(ll i=0; i<n; i++){
            ll win = 
            x_need +=(a[i])/2+1;                            
        }
        if(x<x_need || x<y+n) {
            o1("NO");
            return;
        }
        o1("YES");
        return;
    }
    else{
        
        ll rem = 0;
        ll x_need = 0, y_need = 0;
        for(ll i=0; i<n; i++){
            ll win = (a[i])/2+1;            
            if(s[i]=='0'){
                x_need += win;
            }
            else{
                y_need += win;
            }                      
        }
        if(x>= x_need && y>=y_need){
            o1("YES");
            return;
        }
        
        o1("NO");
        return;
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