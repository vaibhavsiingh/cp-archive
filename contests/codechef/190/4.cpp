#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        // Compute initial sum of adjacent minima
        ll S = 0;
        if(n >= 2){
            for(int i = 0; i < n-1; i++){
                S += min(a[i], a[i+1]);
            }
        }
        // Process queries
        while(q--){
            int p;
            ll X;
            cin >> p >> X;
            int idx = p - 1; // convert to 0-based
            if(n >= 2){
                // Subtract old contributions
                if(idx > 0){
                    S -= min(a[idx-1], a[idx]);
                }
                if(idx < n-1){
                    S -= min(a[idx], a[idx+1]);
                }
            }
            // Update the element
            a[idx] = X;
            if(n >= 2){
                // Add new contributions
                if(idx > 0){
                    S += min(a[idx-1], a[idx]);
                }
                if(idx < n-1){
                    S += min(a[idx], a[idx+1]);
                }
            }
            // Output current f(A)
            cout << S << "\n";
        }
    }

    return 0;
}
