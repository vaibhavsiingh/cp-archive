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
    ll n,m;
    cin >> n >> m;
    priority_queue<ll> a,b;
    for(ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push(x);
    }
    for(ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b.push(x);
    }
    bool finish = false;
    ll turn = 0;
    while(!finish){
        ll x = a.top();            
        ll y = b.top();
        if(turn==0){
            b.pop();
            if(x<y) b.push(y-x);
         //   else o1("Bob lost one");
        }
        else{
            a.pop();
            if(y<x) a.push(x-y);
         //   else o1("Alice lost one");
        }
        turn = (turn+1)%2;
        if(a.empty() || b.empty()) finish = true;
    }
    if(a.empty()) o1("Bob");
    else o1("Alice");
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