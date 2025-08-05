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
    ll n,x;
    i2(n,x);
    vector<pll> v(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i].ff;
        v[i].ss = i+1;
    }
    sort(v.begin(), v.end());
    ll p1=0,p2=1,p3=n-2,p4=n-1;
    for(p1 =0; p1<n-3; p1++){
        for(p2 = p1+1; p2 < n-2; p2++) {
            p3 = p2 +1, p4 = n-1;
            ll sum;
            while(p3<p4){
                sum = v[p1].ff + v[p2].ff+v[p3].ff+v[p4].ff;
                if(sum==x){
                    cout << v[p1].ss << ' ' << v[p2].ss << ' ' << v[p3].ss << ' ' << v[p4].ss << "\n";
                    return;
                }
                if(sum < x){
                    p3++;
                }
                else p4--;
            }
        }
        
    }
    o1("IMPOSSIBLE");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}