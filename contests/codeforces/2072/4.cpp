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
    vll v(n);
    iArray(v,n);
    ll total_inversions = 0;
    // vll dp(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[i]>v[j]) {
                total_inversions++;
       //         dp[i]++;
            }
        }
    }
    // vll prefix_sum(n);
    // prefix_sum[0] = dp[0];
    // for(int i = 1; i < n; i++) {
    //     prefix_sum[i] = prefix_sum[i-1] + dp[i];
    // }


    ll mn = total_inversions;
    // ll base = 0;
    ll x=0,y=0;
    for(int i=0; i<n; i++){
        // base = (i>0) ? prefix_sum[i-1] : 0;
        ll var=0;
        for(int j =i+1; j<n; j++){
            if(v[j]>v[i]) var++;
            else if(v[j]<v[i]) var--;
            ll temp = total_inversions+var;
            if(temp < mn){
                x=i;
                y=j;
                mn = temp;
            }
            // o2(i,j);
            // o1(temp);
        }
    }
    o2(x+1,y+1);
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