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
    ll n;
    cin >> n;
    vector<vector<ll>> v(n,vll(3));
    for(ll i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), [](const vll &a, const vll &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    vll contained(n);
    ll mx = 0;
    for(int i=0; i<n; i++){
        if(v[i][1]>mx){
            mx = v[i][1];
        }
        else{
            contained[v[i][2]] = 1;
        }
    }
    
    vll contains(n);
    sort(v.begin(), v.end(), [](const vll &a, const vll &b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });
    mx = 0;
    for(ll i = 0; i < n; i++) {
        if(mx < v[i][0]){
            mx = v[i][0];
        }
        else{
            contains[v[i][2]] = 1;
        }
    }
    oArray(contains,n);
    oArray(contained,n);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}