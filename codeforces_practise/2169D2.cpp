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
const ll INF = 1e12;

void sol(){
    ll x,y,k;
    cin >> x >> y >> k;
    
    ll actions_done = 0;
    if(y==1){
        o1(-1);
        return;
    }
    while(actions_done < x) {
        
        ll curr = (k-1)/(y-1);
        if(curr == 0){
            break;
        }
        ll next_val_at = (curr+1)*(y-1)+1;
        ll num_actions = (next_val_at - k + curr - 1)/curr;
        num_actions = min(num_actions, x-actions_done);
        actions_done += num_actions;
        k += curr*num_actions;
        if(k>1e12){
            o1(-1);
            return;
        }
    }
    
    o1(k);
            
    
    
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