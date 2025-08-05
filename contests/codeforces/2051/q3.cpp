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
    ll a[m];
    iArray(a,m);
    ll q[k];
    iArray(q,k);
    if(k<n-1){
        for(int i=0; i<m; i++) cout << 0;
        cout << "\n";
        return;
    }
    else if(k==n){
        for(int i=0; i<m; i++) cout << 1;
        cout << "\n";
        return;
    }
    vector<ll> knows(n+1);
    for(ll i=0; i<k; i++){
        knows[q[i]]++;
    }
    ll notKnow = -1;
    for(int i=1; i<=n; i++){
        if(knows[i]==0){
            notKnow = i;
            break;
        }
    }
    for(int i=0; i<m; i++){
        if(a[i]==notKnow){
            cout << 1;
        }
        else cout << 0;
    }
    cout << "\n";
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