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

// --- DSU structure ---
struct DSU {
    vector<int> parent;
    vector<int> compSize;
    DSU(int n) {
        parent.resize(n);
        compSize.resize(n,1);
        for (int i=0; i<n; i++){
            parent[i]=i;
        }
    }
    int find(int a) {
        return parent[a] = (parent[a]==a ? a : find(parent[a]));
    }
    void merge(int a, int b) {
        a = find(a); b = find(b);
        if(a==b)return;
        if(compSize[a] < compSize[b]) swap(a,b);
        parent[b] = a;
        compSize[a] += compSize[b];
    }
    int size(int a) {
        return compSize[find(a)];
    }
};
// --- End DSU ---

// Global variables for the tree.
int n;
vector<vector<int>> adj;

// sol() will solve one test case.
void sol(){
    cin >> n;
    // Build the tree.
    adj.assign(n, vector<int>());
    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        // assuming 0-indexed vertices
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    // We now want to compute, for each m in [0, n],
    // the size of the largest connected component in the subgraph induced by vertices with label >= m.
    // We'll process vertices in decreasing order.
    vector<int> largestComp(n+1, 0); // largestComp[m] for m in 0..n.
    vector<bool> added(n, false);
    DSU dsu(n);
    int global_max = 0;
    // Note: For m = n, the subgraph induced by vertices with label >= n is empty.
    largestComp[n] = 0;
    
    // Process m from n-1 down to 0.
    // When processing m, we "add" vertex m.
    for (int m = n-1; m >= 0; m--){
        added[m] = true;
        // For each neighbor of vertex m that has already been added, merge them.
        for (int nb : adj[m]){
            if(added[nb]){
                dsu.merge(m, nb);
            }
        }
        // Update global maximum component size among vertices added so far.
        global_max = max(global_max, dsu.size(m));
        largestComp[m] = global_max;
    }
    
    // Now, using the “duality” one may show that if we define for each candidate m (which is a potential value for f(S))
    // the quantity:
    //     cand[m] = m + largestComp[m] - 1
    // then for any set S with f(S) >= m one can have |S| at most cand[m].
    // (The “-1” adjusts for the fact that if we pick all dangerous vertices 0,...,m-1 then one vertex from the added part is double–counted.)
    // Thus, for each m from 1 to n, if cand[m] >= k then there exists some set S of size k with f(S) >= m.
    // Hence, for each k (2<=k<=n) the answer is the maximum m in [1,n] with cand[m] >= k.
    vector<pll> cand; // pair: (candValue, m)
    // We consider candidate m from 1 to n.
    for (int m = 1; m <= n; m++){
        // For m = n, note that the subgraph induced by vertices with label >= n is empty so largestComp[n]=0.
        int cur = m + largestComp[m] - 1;
        cand.push_back({cur, m});
    }
    
    // Sort candidates in descending order by candValue.
    sort(cand.begin(), cand.end(), [](const pll &a, const pll &b) {
        return a.first > b.first;
    });
    
    // For each k from 2 to n, we wish to find the maximum m (i.e. the largest second component)
    // among those candidates with candValue >= k.
    vector<int> ans(n+1, 0);
    int ptr = 0;
    int curMaxM = 0;
    // Iterate k from n down to 2.
    for (int k = n; k >= 2; k--){
        // While there are candidates with candValue >= k, update curMaxM.
        while(ptr < (int)cand.size() && cand[ptr].first >= k){
            curMaxM = max(curMaxM, (int)cand[ptr].second);
            ptr++;
        }
        ans[k] = curMaxM;
    }
    
    // Output answers for each k from 2 to n.
    // (If no candidate is found for some k, answer is 0.)
    for (int k = 2; k <= n; k++){
        cout << ans[k] << " ";
    }
    cout << "\n";
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
