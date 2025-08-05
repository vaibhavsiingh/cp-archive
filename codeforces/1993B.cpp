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
    ll nodd=0,neven=0,largestOdd=-1,largestEven=-1;
    for(ll i=0; i<n; i++){
        ll temp;
        cin >> temp;
        a[i] = temp;
        if(temp%2==0){
            ++neven;
            largestEven = max(largestEven,temp);
        }
        else{
            ++nodd;
            largestOdd = max(largestOdd,temp);
        }
    }
    if(nodd*neven==0){
        o1(0);
        return;
    }
    if(largestEven < largestOdd){
        o1(neven);
        return;
    }
    sort(a,a+n);
    ll steps=0;
    for(int i=0; i<n; i++){
        if(a[i]<largestOdd && a[i]%2==0){
            largestOdd+=a[i];
            ++steps;
        }
        else if(a[i]>largestOdd && a[i]%2==0){
            ++steps;
            largestOdd += largestEven;
            --i;
        }
        
    }
    o1(steps);

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
