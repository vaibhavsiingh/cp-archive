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
    vector<pll> v(2*n);
    for(ll i = 1; i <= n; i++) {
        cin >> v[i-1].ff >> v[i+n-1].ff;
        v[i-1].ss = -i;
        v[i+n-1].ss = i;
    }
    sort(v.begin(), v.end());

    // for(ll i = 0; i < 2*n; i++) {
    //     cout << v[i].ff << ' ';
    // }
    // cout << "\n";
    // for(ll i = 0; i < 2*n; i++) {
    //     cout << v[i].ss << ' ';
    // }
    ll count =0, mx =1;
    stack<ll> stk;
    stk.push(1);
    vll ans(n+1);
    for(int i=0; i<2*n; i++){
        if(v[i].ss >0){
            count--;
            ll idx = v[i].ss;
            stk.push(ans[idx]);
            //cout << "Room left now: " << ans[idx] << "\n";
        }
        else{
            count++;
            ll idx = -v[i].ss;
            if(mx<count || stk.empty()){
                mx++;
                ans[idx] = mx;
            }
            else{
                ll x = stk.top();
                ans[idx] = x;
                stk.pop();
            }
           // cout << "Room occupied now: " << ans[idx] << "\n";
        }
    }
    o1(mx);
    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}