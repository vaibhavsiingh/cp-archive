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

struct CustomCompare {
    bool operator()(int a, int b) const {
        return a > b; // Sort in descending order
    }
};


int main() {
    std::set<int, CustomCompare> mySet = {5, 2, 8, 1, 9};

    for (int x : mySet)
        std::cout << x << " "; // Output: 9 8 5 2 1 (sorted in descending order)
        
    vector<vll> v;
    // custom sort of vector of vectors
    sort(v.begin(), v.end(), [](const vector<ll> &a, const vector<ll> &b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    });

    return 0;
}


