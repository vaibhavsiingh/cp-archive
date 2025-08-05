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

const int INF = 1e9;


vector<bool> sieve(ll n) {
    vector<bool>primes(n+1,1);
    vector<int>prime;
    for(int i=2;i<=n;i++){
        if(primes[i]){
            prime.push_back(i);
            int j=2*i;
            while(j<=n){
                primes[j]=0;
            j+=i;
            }
        }
    }
    return primes;
}


bool bfs(const vector<vector<int>> &g, const vector<int> &pairL, const vector<int> &pairR, vector<int> &dist, int n) {
    queue<int> Q;
    for (int u = 0; u < n; u++) {
        if (pairL[u] == -1) {
            dist[u] = 0;
            Q.push(u);
        } else {
            dist[u] = INF;
        }
    }
    int nil_dist = INF;
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (dist[u] < nil_dist) {
            for (int v : g[u]) {
                int pu = pairR[v];
                if (pu == -1) {
                    nil_dist = dist[u] + 1;
                } else if (dist[pu] == INF) {
                    dist[pu] = dist[u] + 1;
                    Q.push(pu);
                }
            }
        }
    }
    return nil_dist != INF;
}

bool dfs(int u, const vector<vector<int>> &g, vector<int> &pairL, vector<int> &pairR, vector<int> &dist, int nil_dist) {
    if (dist[u] == INF) return false;
    for (int v : g[u]) {
        int pu = pairR[v];
        if (pu == -1 || (dist[pu] == dist[u] + 1 && dfs(pu, g, pairL, pairR, dist, nil_dist))) {
            pairL[u] = v;
            pairR[v] = u;
            return true;
        }
    }
    dist[u] = INF;
    return false;
}

pair<int, vector<int>> hopcroftKarp(const vector<vector<int>> &g, int n, int m) {
    vector<int> pairL(n, -1), pairR(m, -1);
    vector<int> dist(n);
    int matching = 0;
    
    while (bfs(g, pairL, pairR, dist, n)) {
        for (int u = 0; u < n; u++) {
            if (pairL[u] == -1 && dfs(u, g, pairL, pairR, dist, 0))
                matching++;
        }
    }
    return {matching, pairL};
}

void sol(){
    int n;
    
    cin >> n;
    vll evens, odds;
    if(n%2){
        for(int i=3; i<=n; i+=2){
            odds.pb(i);
        }
    }
    else{
        for(int i=1; i<=n; i+=2){
            odds.pb(i);
        }
    }
    for(int i=2; i<=n; i+=2){
        evens.pb(i);
    }

    ll max_even = *max_element(evens.begin(), evens.end());
    ll max_odd = *max_element(odds.begin(), odds.end());
    ll max_sum = max_even + max_odd;
    vector<bool> is_prime = sieve(max_sum);


    vector<vector<int>> g(n);
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++){
            if (is_prime[ evens[i] + odds[j] ]) {
                g[i].pb(j);
            }
        }
    }
    
    auto result = hopcroftKarp(g, n/2, n/2);
    int matchingSize = result.first;
    vector<int> matchL = result.second;
    
    

    vll ans(n);
    if(n%2){
        ans[n/2] = 1;
    }
    for(int i=0; i<n/2; i++){
        if(matchL[i]==-1){
            o1(-1);
            return;
        }
        else{
            ans[i] = evens[i];
            ans[n-1-i] = odds[i];
        }
        
    }
    oArray(ans,n);
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
