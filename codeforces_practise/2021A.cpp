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
    stack<ll> eve,odd;
    for(int i=0; i<n; i++){
        ll t;
        cin >> t;
        if(t%2) odd.push(t);
        else eve.push(t);
    }
    while(odd.size()>1 || eve.size()>1){
        if(odd.size()>1){
            ll x = odd.top(); odd.pop();
            ll y = odd.top(); odd.pop();
            ll k = (x+y)/2;
            if(k%2) odd.push(k);
            else eve.push(k);
        }
        if(eve.size()>1){
            ll x = eve.top(); eve.pop();
            ll y = eve.top(); eve.pop();
            ll k = (x+y)/2;
            if(k%2) odd.push(k);
            else eve.push(k);
        }
        
    }
    if(!odd.empty() && !eve.empty()){
        //o1('ueaj');
        o1((odd.top()+eve.top())/2);
        return;
    }
    else if(!odd.empty()){
        o1(odd.top());
    }
    else o1(eve.top());
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