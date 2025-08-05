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
const int INF = 1e9 + 11;


void sol(){
    ll n,m;
    i2(n,m);
    vll gain(n+1);
    for(ll i = 0; i < n; i++) {
        cin >> gain[i+1];
    }
    vector<vector<pll>> adj(n+1);
    for(ll i = 0; i < m; i++) {
        ll x,y,z;
        cin >> x >> y >> z;
        adj[x].pb({y,z});
    }

    ll l = 0, r = INF;
    ll x;

    auto check = [&](ll  num_batt){
        vll best(n+1,0);

        for(int i=1; i<=n; i++){
            if(i>1 && best[i]==0){
                continue;
            }
            best[i]+=gain[i];
            best[i]=min(best[i],num_batt);
            for(auto [c,w]:adj[i]){
                if(w>best[i]) continue;
                best[c] = max(best[c],best[i]);
            }
        }
        return (best[n]>0);
    };

    if(!check(INF)){
        o1(-1);
        return;
    }

    while(l<r){
        ll md = (l+r)/2;
        x  = check(md);
        if(!x) l= md+1;
        else{
            r=md;
        }
    }
    o1(l);
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