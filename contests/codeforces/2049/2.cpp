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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool pOccured = false;
    for(int i=0; i<n-1; i++){
        if(pOccured && s[i]=='s'){
            o1("NO");
            return;
        }
        if(!pOccured && s[i]=='p'){
            pOccured = true;
        }
    }
    int lastS=-1,firstP = -1;
    for(int i=0; i<n; i++){
        if(s[i]=='s') lastS = i;
    }
    for(int i=0; i<n; i++){
        if(s[i]=='p') {
            firstP = i;
            break;
        }
    }
    if(lastS == 0 || firstP == n-1 || lastS == -1 || firstP == -1){
        o1("YES");
    }
    else o1("NO");
     
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