#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define pb push_back
#define ff first
#define ss second
#define o1(a) cout << a << "\n"
#define i2(a, b) cin >> a >> b;

const ll MOD = 1000000007;

ll n, m;
vector<vll> adj;
vector<vll> rev_adj;
vll ncoins;
vll visited;
vll scc;
vll sccCoins;

void dfs(ll start, stack<ll>& stk) {
    stack<pair<ll, bool>> s;
    s.push({start, false});

    while (!s.empty()) {
        auto [nd, processed] = s.top();
        s.pop();

        if (processed) {
            stk.push(nd);
            continue;
        }

        if (visited[nd]) continue;
        visited[nd] = 1;
        s.push({nd, true});

        for (auto x : adj[nd]) {
            if (!visited[x]) {
                s.push({x, false});
            }
        }
    }
}

void rdfs(ll start, ll sccId, ll& count) {
    stack<ll> s;
    s.push(start);
    while (!s.empty()) {
        ll nd = s.top();
        s.pop();
        if (visited[nd]) continue;
        visited[nd] = 1;
        scc[nd] = sccId;
        count += ncoins[nd];
        for (auto x : rev_adj[nd]) {
            if (!visited[x]) {
                s.push(x);
            }
        }
    }
}

void sol() {
    i2(n, m);
    ncoins.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> ncoins[i];
    }

    adj.assign(n + 1, {});
    rev_adj.assign(n + 1, {});
    visited.assign(n + 1, 0);

    for (ll i = 0; i < m; i++) {
        ll x, y;
        i2(x, y);
        adj[x].pb(y);
        rev_adj[y].pb(x);
    }

    stack<ll> stk;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i, stk);
    }

    visited.assign(n + 1, 0);
    scc.resize(n + 1);
    ll nscc = 0;
    sccCoins.clear();
    
    while (!stk.empty()) {
        ll x = stk.top();
        stk.pop();
        if (!visited[x]) {
            ll count = 0;
            rdfs(x, nscc, count);
            sccCoins.push_back(count);
            nscc++;
        }
    }

    vector<set<ll>> sccAdj(nscc);
    vll indeg(nscc, 0);
    for (ll i = 1; i <= n; i++) {
        for (auto x : adj[i]) {
            if (scc[x] != scc[i]) {
                if (sccAdj[scc[i]].insert(scc[x]).second) {
                    indeg[scc[x]]++;
                }
            }
        }
    }

    queue<ll> q;
    for (ll i = 0; i < nscc; i++) {
        if (indeg[i] == 0) q.push(i);
    }

    vll order;
    while (!q.empty()) {
        ll x = q.front();
        q.pop();
        order.pb(x);
        for (auto y : sccAdj[x]) {
            indeg[y]--;
            if (indeg[y] == 0) {
                q.push(y);
            }
        }
    }

    vll dp(nscc);
    for (ll i = 0; i < nscc; i++) {
        dp[i] = sccCoins[i];
    }

    for (ll i = 0; i < nscc; i++) {
        ll curr = order[i];
        for (auto nxt : sccAdj[curr]) {
            dp[nxt] = max(dp[nxt], dp[curr] + sccCoins[nxt]);
        }
    }

    o1(*max_element(dp.begin(), dp.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sol();
    return 0;
}
