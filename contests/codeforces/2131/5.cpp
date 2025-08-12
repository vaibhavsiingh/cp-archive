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
    vll a(n),b(n);
    iArray(a,n);
    iArray(b,n);

    ll j=n-1;
    vll done(n,-1);
    for(int i=0; i<n-1; i++){
        if(a[i]==b[i]) done[i]=i;
        else if((a[i]^a[i+1])==b[i]) done[i]=i+1;
    }
    ll curr =0;
    for(ll i=n-1;i>=0; i--){
        if(done[i]!=-1){
            curr=b[i];
            continue;
        }

        if((a[i]^curr)!=b[i]){
            o1("NO");
            return;
        }        
        curr^=a[i];
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
    return 0;
}