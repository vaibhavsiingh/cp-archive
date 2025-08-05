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
    iArray(a,n);
    bool allSame = true;
    for(ll i = 1; i < n; i++) {
        if(a[i-1]!=a[i]){
            allSame = false;
            break;
        }
    }
    if(allSame){
        o1("No");
        return;
    }
    ll mn = *min_element(a.begin(),a.end());
    ll celement = 0;
    vll ans(n);
    for(int i=0; i<n; i++){
        if(a[i]%mn==0){
            ans[i] = 1;
        }
        else {
            ans[i] = 2;
            celement++;
        }
    }
    if(celement>0){
        o1("Yes");
        oArray(ans,n);
        return;
    }
    else{
        for(int i=0; i<n; i++){
            if(a[i]>mn){
                ans[i] = 2;
                break;
            }
        }
        o1("Yes");
        oArray(ans,n);
        return;
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