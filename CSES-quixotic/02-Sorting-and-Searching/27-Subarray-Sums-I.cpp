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
    vector<ll> v(n);
    iArray(v,n);

    ll p0=0,p1=0;
    ll sum = v[0];
    ll ans = 0;
    while(p0<n && p1<n){
        if(sum==x){
            ans++;
            p1++;
            if(p1<n)sum+= v[p1];
            else break;
            sum-=v[p0];
            p0++;
        }
        else if(sum < x){
            p1++;
            if(p1<n)sum+= v[p1];
            else break;
        }
        else{
            sum-=v[p0];
            p0++;
            if(p0>p1){
                p1++;
                if(p1<n)sum+= v[p1];
                else break;
            }
        }
    }
    o1(ans);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}