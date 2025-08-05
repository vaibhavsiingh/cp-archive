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
    int a[n];
    iArray(a,n);
    int ptr1 = 0, ptr2 = n-1;
    while(ptr1 <n && a[ptr1]==0) ptr1++;
    if(ptr1==n){
        o1(0);
        return;
    }
    while(ptr2>=0 && a[ptr2]==0) ptr2--;
    for(int i=ptr1; i<ptr2; i++){
        if(a[i]==0){
            o1(2);
            return;
        }
    }
    o1(1);
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