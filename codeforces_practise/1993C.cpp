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
    cin >> n >> k;
    vll v(n,0);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    pair<ll,ll> r1 = {0,k};
    ll start=v[0];
    for(int i=0; i<n; i++){
        start = max(start,v[i]);
    }
    
    for(int i=0; i<n; i++){
        ll temp = start - v[i];
        temp %= 2*k;
        if(temp<k){
            if(r1.ss>k-temp)
            r1.ss = k-temp;
        }
        else if(temp > k){
            if(r1.ff < 2*k-temp)r1.ff = 2*k-temp;
        }
        else{
            o1(-1);
            return;
        }
        if(r1.ff >= r1.ss){
            o1(-1);
            return;
        }
    }
    o1(start+r1.ff);
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
    }
}
