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
    vll v(n);
    
    iArray(v,n);
    sort(v.begin(),v.end());
    ll med = 0;
    if(n%2==1){
        med = v[n/2];
    }
    else{
        med = (v[n/2]+v[n/2-1])/2;
    }
    ll ans=0;
    for(ll i = 0; i < n; i++) {
        ans += abs(med-v[i]);
    }
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}