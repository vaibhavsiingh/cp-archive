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
    int n;
    cin >> n;
    if(n==1 || n==3){
        o1(-1);
        return;
    }

    // form a string of length 500 whose all positions are 3 except last 2 whch are 6
    if(!(n%2)){
        string s = "";
        for(int i = 0; i < n-2; i++){
            s+="3";
        }
        s+="66";
        o1(s);
    }
    else{
        string s = "";
        for(int i = 0; i < n-5; i++){
            s+="3";
        }
        s+="36366";
        o1(s);
    }

    



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