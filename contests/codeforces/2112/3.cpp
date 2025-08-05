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
    int n;
    cin >> n;
    vll a(n);
    iArray(a,n);
    sort(all(a));
    ll ans=0;
    ll g = a[n-1];
    ll p1=0,p2=n-2;
    while(p1<p2){
        if(a[p1]+a[p2]<=g){
            p1++;
        }
        else{
            ans+=(p2-p1);
            p2--;
        }
    }

    ll p3=n-2;
    while(p3>=2 && a[p3]+a[p3-1]+a[p3-2]>g){
        p2=p3-1;
        p1=0;
        while(p1<p2){
            if(a[p1]+a[p2]<=a[p3] || a[p1]+a[p2]+a[p3]<=g){
                p1++;
            }
            else{
                ans+=(p2-p1);
                p2--;
            }
        }
        p3--;
    }
    o1(ans);

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