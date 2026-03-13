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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    vll a(2*n);
    iArray(a,2*n)   ;

    queue<ll> q;
    for(ll i=2*n-1; i>=0; i--){
        if(q.empty() || q.front()!=a[i]){
            q.push(a[i]);
        }
        else{
            q.pop();
        }        
    }
    vll v;
    while(!q.empty()){
        v.pb(q.front());
        q.pop();
    }
    
    for(ll i=0; i<v.size() && v.size() -1 -i >= 0 && i<=v.size()-1-i; i++){
        
        if(v[i]!=v[v.size()-1-i]){
            o1("No");
            return;
        }
    }
    o1("Yes");
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
    return 0;
}