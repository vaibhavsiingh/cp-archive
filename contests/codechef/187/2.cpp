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

const ll MOD = 1000000007;

void sol(){
    ll n,x;
    cin >> n >> x;
    vll ans(n,-1);
    vll used(n+1);
    for(int i=1; i<=n; i++){
        if((i|x)==x){
            ll required = (x^i);
            if(required==0){
                used[x] =1;
                ans[i-1] = x;
                continue;
            }
            if(required>n) continue;
            
            ans[i-1] = required;
            used[required] = 1;
        }  
    }
    ll ptr= 1;
    while(used[ptr]==1) ptr++;
    for(int i=0; i<n; i++){
        if(ans[i]==-1){
            ans[i] = ptr;
            used[ptr] = 1;
            while(ptr<n && used[ptr]==1) ptr++;
        }
    }
    oArray(ans,n);
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
}