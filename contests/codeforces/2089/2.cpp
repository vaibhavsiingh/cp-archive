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
    ll n,m;
    cin >> n >> m;
    vector<string> mat(n);
    for(ll i = 0; i < n; i++) {
        cin >> mat[i];
    } 

    vector<vll> contx(n, vll(m));
    vector<vll> conty(n, vll(m));
    for(ll i = 0; i < n; i++) {
        if(mat[i][0]=='1') contx[i][0] = 1;
    }
    for(ll i = 0; i < m; i++) {
        if(mat[0][i]=='1') conty[0][i] = 1;
    }
    // for(ll i = 0; i < n; i++) {
    //     for(ll j=0; j<m; j++){
    //         cout << contx[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // for(ll i = 0; i < n; i++) {
    //     for(ll j=0; j<m; j++){
    //         cout << conty[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(ll i=1; i<n; i++){
        for(ll j=1; j<m; j++){
            if(mat[i][j]=='1'){
                if(contx[i][j-1]==0 && conty[i-1][j]==0) {
               //     o2(i,j);
                    o1("NO");
                    return;
                }
                contx[i][j] = contx[i][j-1];
                conty[i][j] = conty[i-1][j];
            }
            else{
                contx[i][j] = 0;
                conty[i][j] = 0;
            }
        }
    }
    o1("YES");
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