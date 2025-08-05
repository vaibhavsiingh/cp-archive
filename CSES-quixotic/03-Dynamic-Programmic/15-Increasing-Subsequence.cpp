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
    vll a(n);
    iArray(a,n);
    vll ans;
    ans.push_back(a[0]);
    for(ll i = 1; i < n; i++) {
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }
            else{
                ll idx = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
            ans[idx] = a[i];
        }
    }
    o1(ans.size());
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}