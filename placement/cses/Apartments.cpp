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
    ll n,m,k;
    cin >> n >> m >> k;
    
    vll a(n);
    iArray(a,n);

    vll b(m);
    iArray(b,m);

    sort(all(a));
    sort(all(b));

    ll pa=0, ptb=0;
    int cnt = 0;

    while(pa < n && ptb < m){
        // cout << pa << ' ' << ptb << endl;
        // cout << a[pa] << ' ' << b[ptb] << endl;
        if(a[pa]-k <= b[ptb] && b[ptb] <= a[pa] + k){
            cnt++;
            pa++;
            ptb++;
        }
        else if(b[ptb] < a[pa]-k){
            ptb++;
        }
        else if(b[ptb] > a[pa]+k){
            pa++;
        }
    }
    o1(cnt);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}