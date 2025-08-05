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

void sol(){
    string s;
    cin >> s;
    unordered_set<int> st;
    int n = s.size();

    
    for (int i = 0; i + 3 < n; i++) {
        if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') {
            st.insert(i);
        }
    }

    int k;
    cin >> k;
    while (k--) {
        int i, v;
        cin >> i >> v;
        i--; 

        
        s[i] = v + '0';

        
        for (int j = max(0, i - 3); j <= min(n - 4, i); j++) {
            if (s[j] == '1' && s[j+1] == '1' && s[j+2] == '0' && s[j+3] == '0') {
                st.insert(j);
            } else {
                st.erase(j);
            }
        }

        
        if (st.size()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        sol();
    }
}
