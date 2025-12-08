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
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n,m;
    cin >> n >> m;
    vll v(n);
    iArray(v,n);    

    ll mx = 1;

    for(ll i = 0; i < n; i++) {
       mx = max((ll)log10(v[i])+1,mx); 
    }

    vector<vll> mat(n,vll(mx+1));
    vector<unordered_map<ll,ll>> data(mx+1);
    for(ll i = 0; i < n; i++) {
        __int128_t x = v[i];
        for(ll j=0; j<=mx; j++){
            mat[i][j] = x%m;
            x *= 10;            
        }
        data[(ll)floor(log10(v[i]))+1][(__int128_t)v[i]%m]+=1;
    }

    ll ans=0;    
    for(ll i=0; i<n; i++){
        for(ll j=1; j<=mx; j++){
            if(mat[i][j]==0) ans += data[j][0];
            else ans += data[j][m-mat[i][j]];
        }
    }
    o1(ans);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}