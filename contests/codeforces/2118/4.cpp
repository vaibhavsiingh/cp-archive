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
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);
    vll d(n);
    iArray(d,n);

    
    ll q;
    cin >> q;
    while(q--){
        set<pll> s;
        bool done = false;
        ll x;
        cin >> x;
        ll i=0;
        for(; i<n; i++){
            if(a[i]>=x) break;
        }
        if(i==n){
            o1("YES");
            continue;
        }
        ll time = 0;
        ll dir = 1;
        while(!done){        
            ll found = 0;    
            for(;i<n;i+=dir){
                if((time+dir*(a[i]-x))%k==d[i]){
                    if(s.count({i,dir})){
                        done=true;
                        found =1;
                        o1("NO");
                        break;
                    }
                    s.insert({i,dir});
                    x = a[i];
                    time += a[i]-x;
                    dir *= -1;
                    i+=dir;                  
                    found=1;
                    break;  
                }                
            }               
            if(!found){
                o1("YES");
                done = true;
                break;
            }     
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