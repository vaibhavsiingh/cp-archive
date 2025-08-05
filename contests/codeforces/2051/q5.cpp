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
    ll n,k;
    i2(n,k);
    vector<ll> first(n);
    iArray(first,n);
    vector<ll> second(n);
    iArray(second,n);
    ll cust = n, neg = 0;
    vector<pll> comb;
    for(int i=0; i<n; i++) comb.pb({first[i],1});
    for(int i=0; i<n; i++) comb.pb({second[i],2});
    sort(comb.begin(),comb.end());
    ll maxi = -1;
    for(int i=0; i<2*n; i++){
        ll costNow = comb[i].ff;
        int type = comb[i].ss;
        if(neg <=k) maxi = max(maxi,costNow*cust);
        if(type == 1){
            neg++;
        }
        else{
            neg--;
            cust--;
        }
    }
    o1(maxi);
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