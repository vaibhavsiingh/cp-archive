// unsolved


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
    ll n, jump, swim;
    cin >> n >> jump >> swim;
    string s;
    cin >> s;
    ll pos = -1; // start position
    ll swim_rem = swim; // remaining swim distance

    while (true) {
        if (pos + jump >= n) {
            o1("YES");
            return;
        }
        
        bool logF = false;
        for (int i = pos + jump; i > pos; --i) {
            if (i >= n) continue; // Check bounds
            if (s[i] == 'L') {
                pos = i;
                logF = true;
                break;
            }
        }

        if (!logF) {
            if (pos + jump < n && s[pos + jump] == 'C') {
                o1("NO");
                return;
            }
            pos += jump;
            swim_rem--; // Jump into the water
            if (swim_rem < 0) {
                o1("NO");
                return;
            }
            while (pos < n && s[pos] != 'L') {
                if (s[pos] == 'C') {
                    o1("NO");
                    return;
                }
                pos++;
                swim_rem--;
                if (swim_rem < 0) {
                    o1("NO");
                    return;
                }
            }
        }
    }
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
}
