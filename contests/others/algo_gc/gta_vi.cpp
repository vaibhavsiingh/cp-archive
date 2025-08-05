#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

struct Edge {
    int to, gold, health;
};

struct State {
    int gold_cost, health_loss, node;
    bool operator>(const State &other) const {
        return gold_cost > other.gold_cost;
    }
};

vector<int> solve(int n, int m, vector<tuple<int, int, int>> &edges, int s, int t, vector<int> &queries) {
    // Graph representation
    vector<vector<Edge>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        auto &[u, v, h] = edges[i];
        int gold_cost = (1 << i);  // Gold cost is 2^i
        graph[u].push_back({v, gold_cost, h});
        graph[v].push_back({u, gold_cost, h});
    }

    // DP table to store minimum health loss for each (node, gold_cost)
    vector<map<int, int>> dp(n + 1);

    // Priority queue for Dijkstra: (gold_cost, health_loss, node)
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, s});

    while (!pq.empty()) {
        auto [gold_cost, health_loss, node] = pq.top();
        pq.pop();

        // If a better state already exists, skip
        if (dp[node].count(gold_cost) && dp[node][gold_cost] <= health_loss) {
            continue;
        }

        // Update DP table
        dp[node][gold_cost] = health_loss;

        // Explore neighbors
        for (auto &edge : graph[node]) {
            int new_gold_cost = gold_cost + edge.gold;
            int new_health_loss = health_loss + edge.health;

            // Push the new state if it's better
            if (!dp[edge.to].count(new_gold_cost) || dp[edge.to][new_gold_cost] > new_health_loss) {
                pq.push({new_gold_cost, new_health_loss, edge.to});
            }
        }
    }

    // Answer queries
    vector<int> results;
    for (int g : queries) {
        if (!dp[t].size()) {
            results.push_back(-1);  // If `t` is unreachable
            continue;
        }

        int min_health = INF;
        for (auto &[cost, health] : dp[t]) {
            if (cost <= g) {
                min_health = min(min_health, health);
            }
        }

        results.push_back(min_health == INF ? -1 : min_health);
    }

    return results;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;  // (u, v, h) where h = health cost
    for (int i = 0; i < m; ++i) {
        int u, v, h;
        cin >> u >> v >> h;
        edges.emplace_back(u, v, h);
    }

    int s, t, q;
    cin >> s >> t >> q;

    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<int> results = solve(n, m, edges, s, t, queries);
    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
