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
    vector<int> v(n+1);
    string s;
    for(int i=1; i<=n; i++){
        cin >> s;
        //o1(s);
        for(int j=i; j<n; j++){
            if(s[j]=='0'){
                v[i]++;
          //      o1(i);
            }
            else {
                v[j+1]++;
            //    o1(j+1);
            }
        }

    }
    //oArray(v,n+1);
    vector<int> perm(n);
    for(int i=1; i<=n; i++ ){
        perm[v[i]] = i;
    }
    oArray(perm,n);
    return;
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