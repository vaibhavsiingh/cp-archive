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
#define iArray(a, n)           \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a, n)           \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << ' ';   \
    cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

ll nextPowerOf2(ll n) {
    n--;                    
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return n + 1;
}

ll find_ops(ll n)
{
    if (n == 1) return 0;
    if ((n & (n - 1)) == 0) return __builtin_ctzll(n);    
    ll best3mul = 3;
    ll cnt = 1;
    while(best3mul<n) best3mul = (best3mul << 1), cnt++;
    if(n==best3mul) return cnt;
    if(n%8==0){
        return find_ops(n/2)+1;
    }
    else return find_ops(n+4) +1;
}


void sol()
{
    ll n;
    cin >> n;
        if(n%2==0){
        if(n<=6){
            o1(find_ops(n));
            return;
        }
        if(n%4==0){
            o1(find_ops(n));        
        }
        else o1(-1);
        return;
    }
    else{
        if(n<=3){
            o1(find_ops(n));
        }
        else o1(-1);
        return;
    }    
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        sol();
    }
    return 0;
}