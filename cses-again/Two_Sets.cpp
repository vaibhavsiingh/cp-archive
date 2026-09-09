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
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    if(n%4==0){
        o1("YES");
        o1(n/2);
        for(ll i=1; i<=n/4; i++){
            cout << i << ' ' << n + 1 - i << ' ';
        }
        cout << '\n';
        o1(n/2);
        for(ll i=n/4+1; i<=n/2; i++){
            cout << i << ' ' << n + 1 - i << ' ';
        }
        return;
    }
    if((n+1)%4==0){
        o1("YES");
        o1(n/2+1);
        cout << "1 2 ";
        ll cnt = 2;
        ll i=1;
        for(; cnt<(n+1)/2; i++){
            cout << i+3 << ' ' << n + 1 - i << ' ';
            cnt+=2;
        }
        cout << '\n';
        o1(n/2);
        cnt = 1;
        cout << "3 ";
        for(;cnt<(n)/2; i++){
            cout << i+3 << ' ' << n + 1 - i << ' ';
            cnt+=2;
        }
        return;
    }
    o1("NO");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}