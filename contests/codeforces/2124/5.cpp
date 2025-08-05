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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    vll v(n);
    iArray(v,n);
    ll sm = accumulate(all(v),0ll);
    
    if(sm%2){
        o1(-1);
        return;
    }
    ll mx = *max_element(all(v));
    if(2*mx>sm){
        o1(-1);
        return;
    }
    ll cur =0, idx=0;
    for(; idx<n; idx++){
        if(cur+v[idx]>sm/2){
            idx--;
            break;            
        }
        cur += v[idx];
    }

    if(cur==sm/2){
        o1(1);
        oArray(v,n);
        return;
    }

    o1(2);
    vll aa(n);
    ll extra = sm - 2*cur;
    idx++;
    ll temp = extra/2;
    for(;idx<n && temp; idx++){
        if(v[idx]>=temp){
            aa[idx] = temp;
            v[idx] -= temp;
            temp = 0;
        }
        else{
            aa[idx] = v[idx];
            v[idx] = 0;
            temp -= aa[idx];
        }
    }
        
    extra /= 2;

    

    for(int i=n-1;i>=idx && extra; i--){
        if(v[i]>=extra){
            aa[i] = extra;
            v[i] -= extra;
            extra = 0;
        }
        else{
            aa[i] = v[i];
            v[i] = 0;
            extra -= aa[i];
        }
    }

    oArray(aa,n);
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
    return 0;
}