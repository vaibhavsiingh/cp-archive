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
#define reach cout << "Reached" << endl;
#define o1(a) cout << a << "\n"
#define o2(a, b) cout << a << ' ' << b << "\n";
#define iArray(a, n) for (ll i = 0; i < n; i++) cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1000000007;

ll n,q;

const int MAXN = 200005;
const int MAXD = 31;

int parent[MAXN][MAXD]; 



void sol(){
    cin >> n >> q;
    for(ll i = 1; i <= n; i++) {
        cin >>parent[i][0];
    }

    for(ll d=1; d<30; d++){
        for(ll i=1; i<=n; i++){
            parent[i][d] = parent[parent[i][d-1]][d-1];
        }
    }

    while(q--){
        ll nd,k;
        i2(nd,k);
        int y=0;
        while(k){
            if (k&1) nd = parent[nd][y];
            y++; k>>=1;
        }
        o1(nd);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    sol();
}