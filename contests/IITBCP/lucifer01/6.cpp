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

const ll MOD = 1000000007;

void sol(){
    ll a,b,c,l;
    cin >> a >> b >> c >> l;
    ll total_ways=((l+3)*(l+2)*(l+1))/6;

   // o1(total_ways);
    ll count = 0;
    for(ll a1=0; a1<=l; a1++){
        ll x = min(a+a1-b-c,l-a1);
        if(x<0) continue;
        count += ((x+1)*(x+2))/2;
    }
    for(ll a1=0; a1<=l; a1++){
        ll x = min(b+a1-a-c,l-a1);
        if(x<0) continue;
        count += ((x+1)*(x+2))/2;
    }
    for(ll a1=0; a1<=l; a1++){
        ll x = min(c+a1-a-b,l-a1);
        if(x<0) continue;
        count += ((x+1)*(x+2))/2;
    }

    o1(total_ways-count);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}