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

const ll MOD = 1000000007;

void sol(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    string s;
    cin >> s;
    ll b[n];
    for(ll i = 0; i < n; i++) {
         b[i] = s[i]-'0';
    }
    vll ans(n,-1);
    for(int i=0; i<n; i++){
        if(ans[i]!=-1) continue;
        int x = a[i];
        int count=0;
        //o2("aaaa",x);
        while(a[x]!=i){
            if(!b[x]) ++count;
            x = a[x];
        }
        if(!b[x]) ++count;
        if(!b[i] && i!=a[i]) ++count;
    
        x = a[i];
        while(a[x]!=i){
            ans[x] = count;
            x = a[x]; 
        }
        ans[x] = count;
        ans[i] = count;
        
        
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