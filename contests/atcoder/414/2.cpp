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

void sol() {
  int n;
  cin >> n;
  vector<char> v(n);
  vector<ll>  c(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i] >> c[i];
  }

  // 1) sanitize counts
  ll total = 0;
  for (ll &x : c) {
    if (x < 0) x = 0;
    total += x;
    if (total > 100) break;
  }

  if (total > 100) {
    cout << "Too Long\n";
    return;
  }

  string ans;
  ans.reserve((size_t)total);


    for (int i = 0; i < n; i++) {
      ans.append((size_t)c[i], v[i]);
    }
  

  cout << ans << "\n";
}



int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}