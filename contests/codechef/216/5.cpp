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

    vll inorder(n);
    vector<vll> adj(n);
    for(ll i=0; i<n; i++){
        for(ll j=i+1; j<n; j++){
            if((a[i]^a[j])==abs(a[i]-a[j])){
                ll mn = 0, mx = 0;
                if(a[i]>a[j]){
                    mn = j;
                    mx = i;
                }
                else{
                    mx = j;
                    mn = i;
                }
                inorder[mx]++;
                adj[mn].pb(mx);
            }
        }
    }
    queue<ll> q;
    for(ll i=0; i<n; i++) if(inorder[i]==0) q.push(i);
    vll sorted;
    while(!q.empty()){
        ll x = q.front();
        q.pop();
        sorted.pb(x);
        for(auto nd: adj[x]){
            if(--inorder[nd]==0){
                q.push(nd);
            }
        }
    }
    
    vll dp(n,1);
    for(ll i=0; i<n; i++){
        ll curr = sorted[i];
        for(ll x: adj[curr]){
            dp[x] = max(dp[x],dp[curr]+1);     
        }
    }

    o1(*max_element(all(dp)));
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