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
    ll n,m;
    vector<vll> v(2*m+1,vll(2*m+1));
    for(ll i = 1; i <= n; i++) {
        char c1,c2;
        ll x1,x2;
        cin >> c1 >> x1 >> c2 >> x2;
        if(c1=='+' && c2=='+'){
            v[2*m+1-x1][x2] =1;
            
        }
        else if(c1=='-' && c2=='+'){
            v[x1][x2] = 1;
        }
        else if(c1=='-' && c2=='-'){
            v[x1][2*m+1-x2] = 1;
        }
        else{
            v[2*m+1-x1][2*m+1-x2] =1;
        }
    }
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}