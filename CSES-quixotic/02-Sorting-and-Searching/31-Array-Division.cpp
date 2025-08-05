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
    ll n,k;
    i2(n,k);
    vector<ll> v(n);
    iArray(v,n);
    ll l = *max_element(v.begin(),v.end());
    ll r = 0;
    for(ll x:v) r+= x;
  //  r=8;
    
    while(l<r){
  //      o2(l,r);
        ll mid = (r+l)/2;
        int count =0;
        ll sum = 0;
        bool possible  = true;
        for(int i=0; i<n; i++){
            if(sum+v[i]<=mid){
                sum+=v[i];
            }
            else{
                
                if(count<k-1){
                    sum = 0;
                    count++;
                    i--;
                }
                else{
                    //o2("i:",i);
                    for(int j=i;j<n;j++){
                        sum+=v[j];
                      //  o2("j:",j);
                    }
                    if(sum>mid) possible=false;
                    break;
                }
            }
           // o1(sum);

        }
        if(possible){
            r = mid;
        }
        else{
            l= mid+1;
        }
    }
    o1(l);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}