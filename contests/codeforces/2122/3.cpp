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
    ll n;
    cin >> n;
    vector<pll> pointsX(n), pointsY(n); 
    for(ll i = 0; i < n; i++) {
        cin >> pointsX[i].ff;
        cin >> pointsY[i].ff;
        pointsX[i].ss = i+1;
        pointsY[i].ss = i+1;
    }
    
    sort(all(pointsX));
    sort(all(pointsY));

    set<ll> xl,xr,yl,yr;
    for(ll i = 0; i < n/2; i++) {
        xl.insert(pointsX[i].ss);
    }
    for(ll i = n/2; i < n; i++) {
        xr.insert(pointsX[i].ss);
    }
    for(ll i = 0; i < n/2; i++) {
        yl.insert(pointsY[i].ss);
    }
    for(ll i = n/2; i < n; i++) {
        yr.insert(pointsY[i].ss);
    }

    vector<ll> xlyl,xryr,xlyr,xryl;
    for(auto p:xl){
        if(yl.count(p)) xlyl.push_back(p);
        else xlyr.pb(p);
    }
    for(auto p:xr){
        if(yl.count(p)) xryl.push_back(p);
        else xryr.pb(p);
    }
    
    for(ll i=0; i<xlyl.size(); i++){
        o2(xlyl[i],xryr[i]);
    }
    for(ll i=0; i<xlyr.size(); i++){
        o2(xlyr[i],xryl[i]);
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