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
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);

    sort(all(a));

    vll b;
    
    priority_queue<pll, vector<pll>, greater<pll>> q;
    for(ll i = 0; i < n; i++) {
        bool ignore = false;
        if(i>0 && a[i]==a[i-1]) continue;
        while(!q.empty() && q.top().ff==a[i]){
            auto [x,fx] = q.top(); q.pop();
          //  o2("removed from q ", x);
            ll f = x/fx;
            ll t = fx*(f+1);
            //o2(f,t);
            if(t <= k) q.push({t, fx});//o2("added to q ", t);            
            ignore = true;
        }
        if(!q.empty() && q.top().ff < a[i]){
            o1(-1);
            return;
        }        
        if(!ignore){
            b.push_back(a[i]);
           // o2("added to b ", a[i]);
            if(2*a[i]<=k) q.push({2*a[i], a[i]});//, o2("added to q ", 2*a[i]);
            
        }
    }

    if(q.size()>0){
        o1(-1);
    }
    else {
        o1(b.size());
        oArray(b,b.size());
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
    return 0;
}