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
    ll n,k,x;
    cin >> n >> k >> x;
    vll v(n);
    iArray(v,n);
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        sum += v[i];
    }
    if(x>k*sum){
        o1(0);
        return;
    }
    ll num_blocks = (x+sum-1)/sum;
    ll temp_sum=num_blocks*sum;
    ll ptr =0;
    while(ptr<n && temp_sum-v[ptr]>=x){
        temp_sum -= v[ptr];
        ptr++;
    }
    o1((k-num_blocks)*n+ptr+1);
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