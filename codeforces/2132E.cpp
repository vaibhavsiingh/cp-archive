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
    ll n,m,q;
    cin >> n >> m >> q;

    vll a(n), b(m);
    iArray(a,n);
    iArray(b,m);

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());

    unordered_map<ll,ll> sa, sb;
    sa[-1] = 0; sb[-1]=0;
    sa[0] = a[0]; sb[0] = b[0];
    for(ll i=1; i<n; i++) sa[i] = sa[i-1]+a[i];
    for(ll i=1; i<m; i++) sb[i] = sb[i-1]+b[i];

    vector<pll> ideal(n+m+1);
    ll l=0,r=0;

    for(ll z = 1; z <= n+m; z++) {
        if(l==n) ideal[z] = {l,++r};
        else if(r==m) ideal[z] = {++l,r};
        else{
            if(a[l]<b[r]) ideal[z] = {l,++r};
            else ideal[z] = {++l,r};
        }
    //    cout << ideal[z].ff << ' ' << ideal[z].ss << endl;
    }


    for(ll i = 0; i < q; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        ll xi = ideal[z].ff, yi = ideal[z].ss;
        
        if(x>=xi && y>=yi){
            o1(sa[xi-1]+sb[yi-1]);            
        }
        else if(x>=xi && y<yi){
            o1(sb[y-1]+sa[min({n,z-y,x})-1]);
        }
        else if(x<xi && y>=yi){
            o1(sa[x-1]+sb[min({m,z-x,y})-1]);
        }
        else{
            o1(sa[x-1]+sb[y-1]);
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