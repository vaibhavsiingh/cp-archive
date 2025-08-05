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
    ll n;
    cin >> n;
    vll a(n);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll mx = *max_element(a.begin(),a.end());
    ll mx_idx = -1;
    for(ll i = 0; i < n; i++) {
        if(a[i]==mx){
            mx_idx = i;
            break;
        }
    }
    if(mx_idx%2){
        for(int i=mx_idx+1; i<n; i++){
            if(mx==a[i] && i%2==0){
                mx_idx = i;
                break;
            }
        }
    }
    ll total_plus = (n-1)/2;
    if(mx_idx%2){
        o1(mx+total_plus-1);
    }
    else{
        o1(mx+total_plus);
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