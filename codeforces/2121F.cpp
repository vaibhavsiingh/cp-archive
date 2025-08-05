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
    ll n,s,x;
    cin >> n >> s >> x;
    vector<ll> arr(n);
    iArray(arr,n);
  
    unordered_map<ll ,ll> m;
    ll  count = 0;
    ll lef=-1;
    ll curr=0;
    vll pref(n);
    pref[0] = arr[0];
    for(ll i = 1; i < n; i++) {
        pref[i] = pref[i-1]+arr[i];
    }
    for(int i=0; i<n; i++){
        curr+=arr[i];
        if(arr[i]>x){
            m.clear();
            lef = i;
            continue;
        }
        else if(arr[i]==x){
            //cout << "lef: " << lef << " i: " << i << endl;
            if(lef==-1) m[0]++, lef++;
            
            for(;lef<i; lef++){
                m[pref[lef]]++;
              //  cout << "m["<<pref[lef]<<"] -> " << m[pref[lef]] << endl;
            }
        }
        if(m.count(curr-s)){
            count += m[curr-s];
        }
    }
   
    o1(count);
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