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
    ll n,m,k;
    cin >> n >> m >> k;
    vll a(n),b(m);
    iArray(a,n);
    iArray(b,m);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ptra = 0, ptrb=0;
    int ans = 0;
    while(ptra<n && ptrb < m){
        if(a[ptra]-k<=b[ptrb] && a[ptra]+k>=b[ptrb]){
            ans++;
            ptra++;
            ptrb++;
        }
        else if(a[ptra]-k>b[ptrb]){
            ptrb++;
        }
        else{
            ptra++;
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
