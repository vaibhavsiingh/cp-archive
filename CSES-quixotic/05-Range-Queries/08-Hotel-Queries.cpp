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
    ll n,m;
    cin >> n >> m;
    ll N = (1<<((ll)ceil(log2(n))));    
    vll a(2*N);
    for(ll i=N-1; i<N+n-1; i++){
        cin >> a[i];
    }
    
    for(ll i=N-2; i>=0; i--){
        a[i] = max(a[2*i+1], a[2*i+2]);
    }
   // oArray(a,2*n);

    while(m--){
        ll x;
        cin >> x;
        ll i=0;
        if(x>a[i]) {
            cout << 0 << endl;
            continue;
        }
        
        
        while(i<N-1){
            if(a[2*i+1]>=x) i = 2*i+1;
            else i = 2*i+2;          
        }
        cout << i-N+2 << endl;        
        a[i] -= x;
        i=(i-1)/2;
        while(i>0){
            a[i]= max(a[2*i+1],a[2*i+2]);
            i=(i-1)/2;
        }                       
        if(N>1) a[0] = max(a[1],a[2]);
        
        
    }
    o1("");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}