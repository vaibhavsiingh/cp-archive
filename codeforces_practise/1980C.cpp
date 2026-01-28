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
    ll a[n],b[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll m;
    cin >> m;
    int d[m];
    for(ll i = 0; i < m; i++) {
        cin >> d[i];
    }

    map<int,int> mp;
    for(ll i = 0; i < n; i++) {
        if(a[i]!=b[i]){
            mp[b[i]]++;
        }
    }

    ll last=d[m-1];
    bool faltu=true;
    for(ll i = 0; i < n; i++) {
        if(b[i]==last){
            faltu = false;
            break;
        }
    }

    if(mp.find(d[m-1])==mp.end() && faltu){
        cout << "No\n";
        return;
    }

    for(ll i=m-1; i>=0; i--){
        mp[d[i]]--;
    }
    for(auto itr=mp.begin(); itr!=mp.end(); itr++){
        if(itr->second > 0){
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
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