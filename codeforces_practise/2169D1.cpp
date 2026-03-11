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
    ll x,y,k;
    cin >> x >> y >> k;
    for(ll i=0; i<x; i++){
        ll l=1,r=1e12;
        ll kdash=-1;
        while(l<=r){
           // o2(l,r);
            ll md = (l+r)/2;
            ll res = md - md/y;
            if(res<k){
                l = md+1;
            }
            else if(res >k){
                r = md-1;
            }
            else{
                if(md%y==0) kdash = md-1;
                else kdash = md;
                break;
            }
        }
        if(kdash == -1){
            o1(-1);
   //         o1("");
            return;
        }
        k = kdash;
    //    o1(k);
    }
    o1(k);
   // o1("");
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