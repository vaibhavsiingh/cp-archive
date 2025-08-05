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
    ll x,y,z,a,b,c;
    cin >> x >> y >> z >> a >> b >> c;
    ll ans=0;
    if(x>=a){
        ans+=a;
    }
    else if(x+y>=a){
        ans+=a;
        a-=x;
        y-=a;
    }
    else if(x+y+z>=a){
        ans+=a;
        a-=x+y;
        y=0;
        z-=a;
    }
    else{
        ans+=x+y+z;
        o1(ans);
        return;
    }
    if(y>=b){
        ans+=b;
    }
    else if(y+z>=b){
        ans+=b;
        b-=y;
        z-=b;
    }
    else{
        ans+=y+z;
        o1(ans);
        return;
    }
    if(z>=c){
        ans+=c;
    }
    else{
        ans+=z;
       
    }
    o1(ans);
        return;

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
        //reach;
    }
}