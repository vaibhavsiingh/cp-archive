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
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    iArray(a,n);
    ll total_sum = 0;
    for(ll i = 0; i < n; i++) {
        total_sum+=a[i];
    }
    sort(a.begin(),a.end());
    ll count=0;
    for(ll i=0; i<n;i++){
        ll temp = total_sum - a[i];
        if(temp <= x) continue;
        if(temp<=y){
            ll icantremove = temp-x;
            ll end = upper_bound(a.begin()+i+1,a.end(),icantremove) - a.begin();
            count += end-i-1;
            continue;
        }
        ll iwant = temp-y, idontwant = temp-x;
        ll start = lower_bound(a.begin()+i+1,a.end(),iwant) - a.begin();
        ll end = upper_bound(a.begin()+i+1,a.end(),idontwant) - a.begin();
        count += end- start;

    }
    o1(count);
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