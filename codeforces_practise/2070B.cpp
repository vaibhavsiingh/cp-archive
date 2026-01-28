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
    ll n,x,k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll pos = x;
    ll xAt = -1;
    ll zeroReached = -1;
    for(ll i = 0; i < n; i++) {
        if(s[i]=='L') pos--;
        else pos++;
        if(xAt<0 && pos==x){
            xAt = i+1;
        }
        if(pos==0 && zeroReached<0) {
            zeroReached=i+1;
        }
    }
    if(zeroReached<0 || zeroReached>k){
        o1(0);
        return;
    }

    if(zeroReached<=k && xAt<0){
        //o1("2");
        o1(1);
        return;
    }

    o1((k-zeroReached)/xAt+1);
    
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