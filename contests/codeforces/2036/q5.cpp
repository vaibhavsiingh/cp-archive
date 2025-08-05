#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define oArray(a,n) for(ll i=0; i<n; i++) cout << a[i] << ' '; cout << endl;
#define o1(a) cout << a << "\n"

const ll MOD = 1000000007;

void sol() {
    int n, k, q;
    cin >> n >> k >> q;

    
    vector<vector<ll>> mat(k, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> mat[j][i]; 
        }
    }
    
    
    for (int j = 0; j < k; j++) { 
        for (int i = 1; i < n; i++) {
            mat[j][i] |= mat[j][i - 1]; 
        }
    }
    
    while (q--) {
        int m;
        cin >> m;

        
        int left = 0, right = n - 1; 

        while (m--) {
            int x, c;
            char sign;
            cin >> x >> sign >> c;
            x--; 
            
            if (sign == '<') {
                auto temp = lower_bound(mat[x].begin(), mat[x].end(), c);
                if (temp == mat[x].begin()) {
                    right = -1; 
                    break;
                } else {
                    --temp; 
                    right = min(right, static_cast<int>(temp - mat[x].begin()));
                }
            } else if (sign == '>') {
                auto temp = upper_bound(mat[x].begin(), mat[x].end(), c);
                if (temp == mat[x].end()) {
                    left = n; 
                    break;
                }
                left = max(left, static_cast<int>(temp - mat[x].begin()));
            }
        }

        
        if (left > right) {
            o1(-1);
        } else {
            o1(left+1); 
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    sol();
}
