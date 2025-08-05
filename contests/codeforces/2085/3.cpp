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
    ll x,y;
    i2(x,y);
    if(x==y){
        o1(-1);
        return;
    }
    auto toBinaryArray = [](ll num) -> vll {
        vll bin;
        while (num > 0) {
            bin.pb(num % 2);
            num /= 2;
        }
        return bin;
    };

    vll binx = toBinaryArray(x);
    vll biny = toBinaryArray(y);
    ll backsupport = -1;
    ll k = 0;
    ll n = min(binx.size(),biny.size());
    for(ll i=0; i<n; i++){
       // o2(binx[i],biny[i]);
        if(binx[i]!=biny[i]){
            backsupport = i;
            continue;
        }
        if(binx[i]==1){
            if(backsupport>=0){
                ll temp = 0;
                while(backsupport<i){
                    temp+=(1<<(backsupport));
                    backsupport++;
                }
                x += temp;
                y += temp;
                k += temp;
                binx = toBinaryArray(x);
                biny = toBinaryArray(y);
            }
            else{
                ll temp = (1<<(i));
                x += temp;
                y += temp;
                k += temp;
                binx = toBinaryArray(x);
                biny = toBinaryArray(y);
            }
            n = min(binx.size(),biny.size());
        }
    }
    o1(k);
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