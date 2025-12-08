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
    
    ll n4=0,n8=0;
    for(auto c:s){
        if(c=='4') n4++;
        else n8++;
    }
    x = abs(x);
    y = abs(y);
    if(y<=n8){
        if(x<=n8+n4){
            o1("YES");
        }
        else o1("NO");
        return;
    }
    if(x<=n8){
        if(y<=n8+n4){
            o1("YES");
        }
        else o1("NO");
        return;
    }

    x-=n8;y-=n8;
    if(x+y<=n4){
        o1("YES");
    }
    else o1("NO");

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