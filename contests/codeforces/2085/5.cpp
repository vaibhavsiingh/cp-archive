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
    vll a(n),b(n);
    iArray(a,n);
    iArray(b,n);

    ll suma=0,sumb=0;
    unordered_map<ll,ll> m;
    for(ll i = 0; i < n; i++) {
        suma+=a[i];
        sumb+=b[i];
        m[b[i]]++;
    }

    ll diff = suma-sumb;
    if(diff==0){
        for(ll i=0; i<n; i++){
            if(--(m[a[i]])<0){
                o1(-1);
                return;
            }
        }
        ll mx = *max_element(a.begin(), a.end());
        o1(mx+1);
        return;
    }
    vll factors;
    for(ll i=1; i*i<=diff; i++){
        if(diff%i==0){
            factors.push_back(i);
            factors.push_back(diff/i);
        }
    }
    ll max_b = *max_element(b.begin(),b.end());
  //  oArray(b,n);
  //  o2("max",max_b);
    for(ll maybe_k:factors){
        if(maybe_k <= max_b) continue;
        bool valid = true;
        unordered_map<ll,ll> temp_m = m;
        for(ll i=0; i<n; i++){
            ll temp = a[i]%maybe_k;
            if(temp_m[temp]>0) {
                temp_m[temp]--;
            }
            else{
                valid = false;
                break;
            }
        }
        if(valid){
            o1(maybe_k);
            return;
        }
    }
    o1(-1);
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