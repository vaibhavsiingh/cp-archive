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
    int n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);
    ll count1=1;
    if(n==k){
        for(int i=1; 2*i<=n; i++){
            if (a[2*i-1] != i){
                o1(i);
                return;
            }
        }
        o1(n/2+1);
        return;
    }
    
    while(count1<n && a[count1]==1)count1++;
    if(count1<2){
        o1(1);
        return;
    }

    if(count1 == 2){
        
        o1(1);
        return;
        
    }
    else{
        if(n-count1>=k-1){
            o1(1);
            return;
        }
        else{
            
            
            o1(2);
            return;
            
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
}