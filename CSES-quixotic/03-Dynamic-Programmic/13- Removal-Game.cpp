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
    ll n;
    cin >> n;
    vll v(n);
    iArray(v,n);
    //v.insert(v.begin(),0);
    // map<pll,pll> m;
    vector<pll> m((n+1)*(n+1)+1);
    for(ll i = 0; i <= n; i++) {
        m[i*(n+1)+i] = {0,0};
    }
    for(int i=0;i<n;i++ ){
        m[i*n+i+1] = {v[i],0};
    }
    for(int len = 2; len<=n; len++){
        for(int i=0; i+len<=n; i++){
            ll x1 = v[i]+m[(n+1)*(i+1)+i+len].ss;
            ll x2 = v[i+len-1]+m[(n+1)*i+i+len-1].ss;
            if(x1>x2){
                m[i*(n+1)+i+len] = {x1,m[(n+1)*(i+1)+i+len].ff};
            }
            else{
                m[i*(n+1)+i+len]= {x2,m[(n+1)*i+i+len-1].ff};
            }
        }
    }
    cout << m[n].ff << '\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}