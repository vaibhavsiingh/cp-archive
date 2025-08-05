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

multiset<ll> low;
multiset<ll> high;
ll k;


void ins(ll x){
    ll a = *low.rbegin();
    if(x>a){
        high.insert(x);
        if(high.size()>k/2){
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    }
    else{
        low.insert(x);
        if(low.size()>(k+1)/2){
            high.insert(*low.rbegin());
            low.erase(--low.end());
        }
    }
}

void er(ll x){
    ll a = *low.rbegin();
    if(x>a){
        high.erase(high.find(x));
    }
    else{
        low.erase(low.find(x)); 
    }
    if(low.empty()){
        low.insert(*high.begin());
        high.erase(high.begin());
    }
}



void sol(){
    ll n;
    i2(n,k);
    vector<ll> v(n);
    iArray(v,n);
    low.insert(v[0]);
    for(ll i = 1; i < k; i++) {
        ins(v[i]);
    }
    vll ans;
    ans.push_back(*--low.end());
    for(ll i = k; i < n; i++) {
        if(k==1){
            ins(v[i]);
            er(v[i-k]);
        }
        else{
            er(v[i-k]);
            ins(v[i]);
        }
        ans.push_back(*--low.end());
    }
    oArray(ans,n-k+1);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}