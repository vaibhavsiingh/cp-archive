#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];
    
    // Function to get streak length starting from pos
    auto getStreak = [&](int pos) {
        ll len = 1;
        ll last = a[pos];
        for(int i = pos + 1; i < n && a[i] >= last; i++) {
            len++;
            last = a[i];
        }
        return len;
    };
    
    ll maxStreak = 0;
    // Try without multiplication
    for(int i = 0; i < n; i++) {
        maxStreak = max(maxStreak, getStreak(i));
    }
    
    // Try multiplying each position
    for(int i = 0; i < n; i++) {
        ll original = a[i];
        a[i] *= x;
        
        // Check streaks starting before or at position i
        for(int j = 0; j <= i; j++) {
            maxStreak = max(maxStreak, getStreak(j));
        }
        
        a[i] = original;
    }
    
    cout << maxStreak << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}