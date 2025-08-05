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

int next_beauty(ll x){
    ll i=0;
    while((x&(1ll<<i)) && i<64) i++;
    return i;
}

int beauty(ll x){
    int ans =0;
    for(int i=0;i<64;i++){
        if(x&(1ll<<i)) ans++;
    }
    return ans;
}

void sol(){
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);
    
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    for(int i=0; i<n; i++){
        pq.push({next_beauty(a[i]),i});
       // o2(next_beauty(a[i]),i);
    }
   // reach;
    while((k-(1ll<<pq.top().ff))>=0){
        auto [x,i] = pq.top();
        pq.pop();
        k-=(1ll<<x);
        a[i]+=(1ll<<x);
        pq.push({next_beauty(a[i]),i});
     //   cout << k << endl;
    }
    ll ans = 0;
    for(ll i=0; i<n; i++){
        ans += beauty(a[i]);
      //  o1(beauty(a[i]));
    }
    o1(ans);
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