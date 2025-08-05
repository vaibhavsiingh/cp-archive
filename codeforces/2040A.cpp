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
    int n,k;
    i2(n,k);
    int a[n];
    iArray(a,n);
    for(int i=0; i<n; i++){
        int chosen = a[i];
        bool winnable = true;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(abs(chosen-a[j])%k==0){
                winnable = false;
                break;
            }
        }
        if(winnable){
            o1("YES");
            o1(i+1);
            return;
        }
    }
    o1("NO");
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