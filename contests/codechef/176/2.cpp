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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)

const ll MOD = 1000000007;

void sol(){
    ll n,c;
    i2(n,c);
    string s;
    cin >> s;
    vll langs(32);
    vll freq(5);
    for(ll i = 0; i < n; i++) {
        ll lg=s[i]-'A';
        freq[lg]++;
    }
    ll mn_cost = 1e15;
    for(ll l=0; l<32; l++){
        ll f=0;
        ll cost = 0;
        for(ll shift=0; shift<5; shift++){
            if((l&(1<<shift))==0){
                f+=freq[shift];
            }
            else{
                cost+=c;
            }
        }
        cost += (f*(f+1))/2;
        mn_cost = min(mn_cost,cost);
    }
    o1(mn_cost);
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