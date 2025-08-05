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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

vector<int> to_base(ll x, int A) {
    vector<int> digs;
    while (x > 0) {
        digs.pb(x % A);
        x /= A;
    }
    return digs;
}

bool is_pal(const vector<int>& v) {
    int i = 0, j = v.sz() - 1;
    while (i < j) {
        if (v[i++] != v[j--]) return false;
    }
    return true;
}

void gen_palindromes(int L, ll N, vll &out) {
    int half = (L + 1) / 2;
    ll start = pow(10, half - 1);
    ll end = pow(10, half) - 1;

    for (ll prefix = start; prefix <= end; ++prefix) {
        string s = to_string(prefix);
        string t = s;
        for (int i = (L % 2 ? s.sz() - 2 : s.sz() - 1); i >= 0; --i)
            t.pb(s[i]);
        ll p = stoll(t);
        if (p > N) break;
        out.pb(p);
    }
}

void sol() {
    int A;
    ll N;
    i2(A, N);

    int maxLen = to_string(N).sz();
    vll pals;

    rep(d, 1, 10) {
        if (d > N) break;
        pals.pb(d);
    }

    rep(L, 2, maxLen + 1)
        gen_palindromes(L, N, pals);

    ll sum = 0;
    for (auto p : pals) {
        auto digsA = to_base(p, A);
        if (is_pal(digsA)) sum += p;
    }

    o1(sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    // Uncomment if multiple testcases
    // cin >> t;
    rep0(i, t) sol();
    return 0;
}
