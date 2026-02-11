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

const ll MOD = 998244353;
const ll INF = 1e18;

vector<ll> fac;

ll expo(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp = expo(a,b/2);
    ll ans = (temp*temp)%MOD;
    if(b%2==0){
        return ans;
    }
    else{
        return (ans*a)%MOD;
    }
}


void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);
    sort(all(a));

    vll len(n+1);
    for(ll i=0; i<n; i++){
        ll curr = 1;
        ll  j =i+1;
        for(; j<n; j++){
            if(a[j]==a[j-1]+1 ) curr++;            
            else break;
        }
        len[j-i]++;
        i = j-1;
    }
    ll mx_len = 1;
    for(ll i=n; i>=1; i--){
        if(len[i]>0){
            mx_len = i;
            break;
        } 
    }
  //  o2(mx_len, len[mx_len]);
    ll x = expo(2,mx_len-1)*fac[n-mx_len];
    o1((x*len[mx_len])%MOD);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    fac.resize(2e5+1);
    fac[0] = 1;
    for(ll i=1; i<=2e5; i++) fac[i] = (i*fac[i-1])%MOD;
    for(ll i = 0; i < t; i++) {
        sol();
    }
    return 0;
}