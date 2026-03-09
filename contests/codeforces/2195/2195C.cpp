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
    ll n;
    cin >>  n;
    vll a(n);
    iArray(a,n);
    ll cnt = 0;
    for(ll i=1; i<n; i++){
        if(a[i]+a[i-1]==7 || a[i]==a[i-1]){
            ll pos = 63;
            ll x = a[i-1]-1;
            if(i+1<n){
                ll y = a[i+1]-1;
                pos = pos&(~(1<<y));
                //cout << hex;
                
                y = 5-y;
                pos = pos&(~(1<<y));
                
            }
            cnt++;
            pos = pos&(~(1<<x));
            
            x = 5-x;
            pos = pos&(~(1<<x));
            
            //cout << dec;
            a[i] = -1;
            for(ll j=0; j<6; j++){
                if((pos>>j)&1){
                    a[i] = j+1;
                    break;
                }
            }

        }
    }
  //  oArray(a,n);
    o1(cnt);
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