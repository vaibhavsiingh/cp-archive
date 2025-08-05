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
    int n;
    cin >> n;
    vll v(n);
    iArray(v,n);
    sort(v.begin(),v.end());
    vll suffix(n);
    suffix[0] = v[0];
    for(int i=1; i<n; i++){
        suffix[i] =suffix[i-1]+v[i];
    }
    int ptr_back = n-1;
    double avg = ((double)suffix[n-1]/(double)n);
    while(avg < v[ptr_back]) ptr_back--;
    int mx = n-1-ptr_back ;
    for(int i=n-2; i>=0; i--){
        avg = ((double)suffix[i]/(double)(i+1));
        while(avg < v[ptr_back]) ptr_back--;
        mx = max(mx,i-ptr_back);
    }
    o1(mx);
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