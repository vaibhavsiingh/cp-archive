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
    ll n,m,h;
    cin >> n >> m >> h;
    vll a(n);
    iArray(a,n);
    ll st=0;
    vll extra(n,0);
    vll last_updated(n);
    ll lst_crash=-1;
    for(ll i = 0; i < m; i++) {
        ll x,y;
        cin >> x >>y;
        x--;
        if(lst_crash >= last_updated[x]){
            extra[x] = 0;
            last_updated[x] = lst_crash+1;
        }
        if(extra[x]+a[x]+y>h){
            lst_crash = i;
            extra[x] = 0;
            last_updated[x] = lst_crash+1;
        }
        else{
            extra[x] += y;
            last_updated[x] = i;
        }
    }
    for(ll i=0; i<n; i++){
        if(last_updated[i]<=lst_crash) extra[i]=0;
        cout << a[i] + extra[i] << ' ';
    }
    o1("");
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