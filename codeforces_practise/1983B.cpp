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
    int n,m;
    i2(n,m);
    vector<vll> a(n,vll(m,0));
    vector<vll> b(n,vll(m,0));
    
    for(ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(ll j = 0; j < m; j++) {
            a[i][j] =s[j]-'0';
        }
    }
    
    for(ll i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(ll j = 0; j < m; j++) {
            b[i][j] = s[j]-'0';
        }
    }
    
    for(ll i = 0; i < n; i++) {
        ll suma=0,sumb=0;
        for(int j=0; j<m; j++ ){
            suma+=a[i][j];
            sumb+=b[i][j];
        }
        suma %= 3;
        sumb %=3;
        if(suma!=sumb){
            o1("NO");
            return;
        }
    }
    
    for(ll i = 0; i < m; i++) {
        ll suma=0,sumb=0;
        for(int j=0; j<n; j++ ){
            suma+=a[j][i];
            sumb+=b[j][i];
        }
        suma %= 3;
        sumb %=3;
        if(suma!=sumb){
            o1("NO");
            return;
        }
    }
    o1("YES");    
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