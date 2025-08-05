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
    string s;
    cin >> s;
    bool allOne = true;
    int first0 = -1;
    int n = s.length();
    for(int i=0; i<n; i++){
        if(s[i]=='0'){
            allOne = false;
            first0 = i;
            break;
        }
    }
    if(allOne) {
        cout << 1 << ' ' << n << " 1 1\n"; 
        return;
    }
    string nextsub = s.substr(first0);
    int k = nextsub.length();
    int best = -1,mx=-1;
    for(int i=0; i<=n-k; i++){
        bool bestCase = true;
        for(int j=0; j<k; j++){
            if(nextsub[j]!=s[i+j]) continue;
            else{
               // cout << i+j << ' ' << j << endl;
                if(mx < j-1){
                    best = i;
                    mx = j-1;
                }
                bestCase = false;
                break;
            }
        }
        if(bestCase) {
            best= i;
            break;
        }
    }
    cout << "1 " << n << " " << best+1 << ' ' << best +k << "\n";

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