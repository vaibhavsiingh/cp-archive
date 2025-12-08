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
    vll a(n);
    iArray(a,n);
    unordered_map<ll,ll> m;
    for(ll i = 0; i < n; i++) {
        m[a[i]]++;
    }
    ll ans = 0;
    for(auto [x,y]:m){
        if(y-m[x-1]>0)ans += y-m[x-1];
    }
    

    ll q;
    cin >>q;
    ll ret=0;
    
    for(ll i=1; i<=q; i++){
        ll id,val;
        cin >> id >> val;
        id--;
        ll frq_bef = m[a[id]-1], frq_af = m[a[id]+1], frq = m[a[id]];
        if(frq_af<frq && frq_bef < frq){
            ans--;
        }
        else if(frq_af>=frq && frq_bef>=frq){
            ans++;
        }
        m[a[id]]--;
        
        frq_bef = m[val-1], frq_af = m[val+1], frq = m[val];
        if(frq_af<=frq && frq_bef <= frq){
            ans++;
        }
        else if(frq_af>frq && frq_bef>frq){
            ans--;
        }
        
        m[val]++;
        a[id] = val;
        ll temp  = (ans*i)%MOD;
        ret = (ret+temp)%MOD;

    }
    o1(ret);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
    
    return 0;
}