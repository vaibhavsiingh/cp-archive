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
    int n;
    cin >> n;
    vector<unordered_set<int>> incoming(n+1);
    vector<unordered_set<int>> outgoing(n+1);
    queue<int> q;
    vector<int> ans(n+1,-1);
    for(int i=2; i<=n; i++){
        if(incoming[i].size()==0){
            for(int j=2*i; j<=n; j+=i) outgoing[i].insert(j), incoming[j].insert(i);
            if(outgoing[i].size()==0){
                ans[i] = i;
            }
        }
        if(outgoing[i].size()==1) q.push(i);
    }
 //   reach;
    int curr = 2;
    while(curr<=n){
        while(!q.empty()){
            int x = q.front(); q.pop();
            if(outgoing[x].size()==1){
                int beta = *outgoing[x].begin();
                ans[x] = beta;
                ans[beta] = x;
                for(auto xx:incoming[beta]){
                    outgoing[xx].erase(beta);
                    if(outgoing[xx].size()==1) q.push(xx);
                }
            }
            else ans[x] = x;
        }
        
        if(ans[curr]!=-1) {
            curr++;
            continue;
        }
        int prev = curr;
        for(auto nd: outgoing[curr]){
            ans[nd] = prev;
            prev = nd;
            for(auto x:incoming[nd]){
                if(x==curr) continue;
                outgoing[x].erase(nd);
                if(outgoing[x].size()==1) q.push(x);
            }
        }
        ans[curr] = prev;
        curr++;
    }
    ans[1] =1;
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';


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