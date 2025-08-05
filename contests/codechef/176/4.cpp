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
    string s1,s2;
    cin >> s1;
    cin >> s2;
    ll x=0,y=0,z=0;
    for(ll i=0; i<n; i++){
        if(s1[i]==s2[i]){
            if(s1[i]=='1') z++;
            else x++;
        }
        else y++;
    }
    ll odds=0;
    if(x%2) odds++;
    if(y%2) odds++;
    if(z%2) odds++;
    if(n%2){
        if(odds!=1) o1("NO");
        else o1("YES");
        return;
    }
    if(odds>0) o1("NO");
    else o1("YES");
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