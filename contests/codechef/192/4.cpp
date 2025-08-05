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
    vll a(n);
    iArray(a,n);
    a.insert(a.begin(),0);
    vector<vll> adj(n+1);
    for(ll i = 0; i < n-1; i++) {
        ll x,y;
        i2(x,y);
        adj[x].pb(y);
        adj[y].pb(x);
    }
  //  reach;
   // int count0 =0;
    ll mn = n+1;
    vector<ll> n_neigh_0(n+1);
    vector<ll> max_neigh(n+1,0);

    set<ll> vals_missing;
    for(int i=1; i<=n; i++){
        vals_missing.insert(i);
    }

    for(int i=1; i<=n; i++){        
        for(int neigh:adj[i]){
            if(a[neigh]==0)n_neigh_0[i]++;
            else max_neigh[i] = max(max_neigh[i],a[neigh]);
        } 
        if(a[i]!=0) vals_missing.erase(a[i]);
    }

    // for(ll i = 1; i <= n; i++) {
    //     cout << max_neigh[i] << ' ' << n_neigh_0[i] << endl;
    // }

    vll vals_missing_vec;
    for(auto itr=vals_missing.begin(); itr!=vals_missing.end(); itr++){
        vals_missing_vec.pb(*itr);
    }

    for(int i=1; i<=n; i++){
       // reach;
        if(a[i]==0){
            ll pos_ans = vals_missing_vec[n_neigh_0[i]];
            auto temp = vals_missing.lower_bound(max_neigh[i]);
            if(temp==vals_missing.end()) continue;
            pos_ans = max(pos_ans, *temp);
            mn = min(mn,pos_ans);
        }
        else {
            if(max_neigh[i]>a[i]) continue;
            ll largest0value;
            if(n_neigh_0[i]==0) largest0value=-1;
            else largest0value = vals_missing_vec[n_neigh_0[i]-1];
            //cout << largest0value << endl;
            if(largest0value<a[i]) mn = min(mn,a[i]);
        }
    }
    o1(mn);


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