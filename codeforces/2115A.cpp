#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return __gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int total_gcd = a[0];
        for (int i = 1; i < n; ++i) total_gcd = gcd(total_gcd, a[i]);

        map<int, int> dp;

        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int g = gcd(a[i], a[j]);
                if (dp.find(g) == dp.end()) dp[g] = 1;
                else dp[g] = min(dp[g], 1);
            }
        }

        
        for (int g = 5000; g >= 1; --g) {
            if (dp.find(g) == dp.end()) continue;
            for (int i = 0; i < n; ++i) {
                int x = gcd(g, a[i]);
                if (dp.find(x) == dp.end()) dp[x] = dp[g] + 1;
                else dp[x] = min(dp[x], dp[g] + 1);
            }
        }

        int min_gcd = dp.begin()->first;
        int count=0;
        for(int i=0; i<n; i++){
            count += (a[i]==min_gcd);
        }
        if(count>0) {
            cout << (n-count) << endl;
            continue;
        }
        
        int ops = (dp.find(total_gcd) == dp.end()) ? 0 : dp[total_gcd];
        cout << ops + (n - 1) << '\n';
    }

    return 0;
}
