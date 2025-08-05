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
    ll n,k;
    i2(n,k);
    vector<vector<ll>> v(n,vector<ll>(2));
    string s;
    cin >> s;
    ll mn = LLONG_MAX, mx = LLONG_MIN;
    for(ll i = 0; i < n; i++) {
        cin >> v[i][0];
        v[i][1] = (s[i]=='R')?0:1;
        mn = min(mn,v[i][0]);
        mx = max(mx,v[i][0]);
    }

    ll l = 0, r = mx;
    while(l<r){
        ll mid = (l+r)/2;
        ll nstrokes= 0;
        ll brush_down=0;
        for(int i=0; i<n; i++){
            if(v[i][0]>mid){
                if(brush_down){
                    if(v[i][1]==1) continue;
                    brush_down=0;
                }
                else{
                    if(v[i][1]) {
                        nstrokes++;
                        brush_down=1;
                    }
                }
            }
        }
        if(nstrokes>k){
            l=mid+1;
        }
        else r=mid;
    }
    o1(l);
    
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