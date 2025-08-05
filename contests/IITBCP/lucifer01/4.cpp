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
    string s;
    cin >> s;
    int n_indices = 0;
    for(int i=1; i<n; i++){
        if(s[i-1]==s[i]) {
            n_indices++;
        }
    }
    
    if(n_indices==0 || n_indices==1){
        o1(n);
    }
    else{
        vll last_opposite(n);
        ll last0 =-1, last1=-1;
        for(int i=0; i<n; i++){
            if(s[i]=='0'){
                last0 = i;
                last_opposite[i] = last1;
            }
            else{
                last1 = i;
                last_opposite[i] = last0;
            }
        }
        vll dp2(n);
        dp2[0] = 1;
        for(int i=0; i<n; i++){
            if(last_opposite[i]==-1)dp2[i] = 1;
            else{
                dp2[i] = max(dp2[i-1],dp2[last_opposite[i]]+1);
            }
        }
        o1(dp2[n-1]+2);
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}