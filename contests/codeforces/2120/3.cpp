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
    ll n, m;
    cin >> n >> m;
    if(m>(n*(n+1)/2) || m<n) {
        o1(-1);
        return;
    }

    ll curr=0;
    vector<int> v,v2;
    ll mx = n-1;
    m-=n;
    while(mx>0){
        //o2(curr, mx);
        curr+= mx;
        if(curr>m){
          //  cout << "into v2\n";
            curr-=mx;
            v2.push_back(mx+1);
            mx--;
        }
        else {
        //    cout << "into v\n";
            v.push_back(mx+1);
            mx--;
        }
    }
    if(v.size()==0){
        cout << "1\n";
        for(int i=1; i<n;i++){
            o2(i,i+1);
        }
        return;
    }
    cout << v[0] << '\n';
    for(int i=1; i<v.size(); i++){
        cout << v[i-1] << ' ' << v[i] << '\n';
    }
    cout << v.back() << ' ' << 1 << '\n';
    if(v2.size()>0){
        cout << "1 " << v2[0] << '\n';
        for(int i=0; i<v2.size()-1; i++){
            cout << v2[i] << ' ' << v2[i+1] << '\n';
        }
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
    return 0;
}