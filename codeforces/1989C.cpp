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
    ll a[n],b[n];
    ll sumA=0,sumB=0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll both1 = 0, both_1=0;
    for(ll i = 0; i < n; i++) {
        if(a[i]!=b[i]){
            if(a[i]>b[i]) sumA+=a[i];
            else sumB+=b[i];
        }
        else if(a[i]!=0){
            if(a[i]==1) ++both1;
            else ++both_1;
        }
    }
    ll diff = abs(sumA-sumB);
    if(diff >=both1+both_1){
        if(sumA>sumB){
            sumA-=both_1;
            sumB+=both1;
        }
        else{
            sumB-=both_1;
            sumA+=both1;
        }
        o1(min(sumA,sumB));
    }
    else{
        ll k = both1+both_1;
        ll mx = max(sumA,sumB);
        ll mn = min(sumA,sumB);
        ll k1 = (mn+k-mx)/2;
        mx+=k1-both_1;
        mn+=k-k1-both_1;
        o1(min(mx,mn));
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