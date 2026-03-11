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
    ll n,k;
    cin >> n >> k;
    vll cnt(n+1);
    vll a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll y= -1;
    for(ll i=1; i<=n; i++){
        if(cnt[i]==0){
            y = i;
            break;
        }
    }        
    if(y==-1){
        ll x = a[n-1];
        ll y = a[n-2];                
        ll z = 1;
        if (z == x || z == y) z = 2;
        if (z == x || z == y) z = 3;
        for(ll i=0; i<k; i++){
            if(i%3==0) cout << z << ' ';
            if(i%3==1) cout << y << ' ';
            if(i%3==2) cout << x << ' ';
        }        
    }
    else{
        ll x = a[n-1];
        ll z = 1;
        if (z == x || z == y) z = 2;
        if (z == x || z == y) z = 3;
        for(ll i=0; i<k; i++){
            if(i%3==0) cout << y << ' ';
            if(i%3==1) cout << z << ' ';
            if(i%3==2) cout << x << ' ';
        }        
    }
    cout << '\n';
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