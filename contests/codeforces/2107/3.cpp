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
    ll n, k;
    i2(n,k);
    string s;
    cin >> s;
    vll v(n);
    iArray(v,n);

    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            v[i] = -1e18;
        }
    }

    ll mx=0;
    ll curr = 0;
    for(int i=0; i<n; i++){
        curr = max(curr+v[i],v[i]);
        mx = max(mx,curr);
    }

    if(mx>k){
        o1("No");
        return;
    }
    if(mx==k){
        o1("Yes");
        oArray(v,n);
        return;
    }

    ll idx=0;
    while(s[idx]!='0' && idx<n)idx++;
    if(idx==n){
        o1("No");
        return;
    }
    curr=0;
    for(int i=0; i<idx; i++){
        curr = max(curr+v[i],v[i]);
    }
    ll curr2=0;
    for(int i=n-1;i>idx;i--){
        curr2 = max(curr2+v[i],v[i]);
    }

    v[idx] = k-max(curr,0LL)-max(curr2,0LL);
    o1("Yes");
    oArray(v,n);
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