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
    ll n, k;
    cin >> n >> k;

    vll a(n);
    iArray(a,n);

    if(n == 1){
        o1(max((long long)0, a[0] - k));
        return;
    }

    sort(all(a));
    vll prefixSm(n,0);
    prefixSm[1] = a[1];
    for(ll i=2; i<n; i++){
        prefixSm[i] = prefixSm[i-1] + a[i];
    }

    ll mnTotal = max((ll)0,prefixSm[n-1] + a[0] - k);


    for(ll y=0; y<n; y++){
        ll l=0, r=prefixSm[n-1] - k + a[0] + 1;
        while(l < r){
            ll mid = l + (r-l) / 2;
            __int128 sm =
                (__int128)prefixSm[n-y-1]
                + (__int128)(a[0] - mid) * (y+1);
            if(sm <= k){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        mnTotal = min(mnTotal, l + y);
    }
    o1(mnTotal);
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