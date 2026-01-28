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
    string a,b;
    cin >> a >> b;

    vll diffa(n), diffb(n);
    if(a[0]=='0') diffa[0] = 1;
    else diffa[0] = -1;
    if(b[0]=='1') diffb[0] = 1;
    else diffb[0] = -1;    

    for(ll i = 1; i < n; i++) {
        if(a[i]=='0') diffa[i] = diffa[i-1]+1;
        else diffa[i] = diffa[i-1]-1;
    }   
    for(ll i = 1; i < n; i++) {
        if(b[i]=='1') diffb[i] = diffb[i-1]+1;
        else diffb[i] = diffb[i-1]-1;
    }   

//    oArray(diffa,n);
  //  oArray(diffb,n);
    sort(all(diffa));
    sort(all(diffb));
    vll sa(n), sb(n);
    sa[0] = diffa[0];
    sb[0] = diffb[0];
    for(ll i = 1; i < n; i++) {
        sa[i] = sa[i-1]+diffa[i];
    }
    for(ll i = 1; i < n; i++) {
        sb[i] = sb[i-1]+diffb[i];
    }

    ll p1=n-1, p2 = n-1;
    ll ans = 0;
  //  oArray(sa,n);
   // oArray(sb,n);
    while(p1>=0 && p2>=0){
        if(diffa[p1]>=diffb[p2]){
            ans += (p2+1)*diffa[p1] - sb[p2];
            p1--;
        }   
        else p2--;        
    }
    p1=n-1, p2=n-1;
    while(p1>=0 && p2>=0){
        if(diffa[p1]<diffb[p2]){
            ans += (p1+1)*diffb[p2] - sa[p1];
            p2--;
        }   
        else p1--;        
    }
    
    o1(((n*n*(n+1))-ans)/2);

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