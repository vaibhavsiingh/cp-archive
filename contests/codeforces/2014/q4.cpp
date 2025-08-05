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
    ll n,d,k;
    cin >> n >> d >> k;
    vector<ll> v(n+2,0);
    for(int i=0; i<k; i++){
        ll a,b;
        cin >> a >> b;
        a = max((ll)1,a-d+1);
        b = min(n+1,b+1);
        v[a]++;
        v[b]--;
    }
    int curr = 0;
    ll mn = 1e10,mx = -1;
    ll imn=0,imx  = 0;
    for(int i=1; i<=n-d+1;i++){
        curr += v[i];
        if(curr>mx){
            mx = curr;
            imx = i;
        }
        if(curr<mn){
            mn = curr;
            imn = i;
        }
    }
    o2(imx,imn);
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