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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll x  = sqrt((float)n);
    if(x*x != n){
        o1("NO");
        return;
    }
    for(ll i = 0; i < x; i++) {
        if(s[i]=='0'){
            o1("NO");
            return;
        }
    }
    int ptr = x;
    for(int i=1; i<x-1; i++){
        if(s[ptr]=='0'){
            o1("NO");
            return;
        }
        ptr++;
        for(int j=1; j<x-1; j++){
            if(s[ptr]=='1'){
                o1("NO");
                return;
            }
            ptr++;
        }
        if(s[ptr]=='0'){
            o1("NO");
            return;
        }
        ptr++;
    }
    for(ll i = 0; i < x; i++) {
        if(s[ptr]=='0'){
            o1("NO");
            return;
        }
        ptr++;
    }
    cout << "YES\n";
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
