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
#define iArray(a, n)           \
    for (ll i = 0; i < n; i++) \
        cin >> a[i];
#define i2(a, b) cin >> a >> b;
#define oArray(a, n)           \
    for (ll i = 0; i < n; i++) \
        cout << a[i] << ' ';   \
    cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

vll a;
vector<pll> tree;

void build(ll nd, ll l, ll r)
{
    if (l == r)
    {
        tree[nd] = {-1, a[l]};
        return;
    }
    ll md = (l + r) / 2;
    build(2 * nd, l, md);
    build(2 * nd + 1, md + 1, r);
    if (tree[2 * nd].ff == -1)
        tree[nd].ff = 1;
    else
        tree[nd].ff = tree[2 * nd].ff + tree[2 * nd].ss;
    if (tree[2 * nd + 1].ff == -1)
        tree[nd].ss = 1;
    else
        tree[nd].ss = tree[2 * nd + 1].ff + tree[2 * nd + 1].ss;
}

ll query(ll nd, ll curr, ll i)
{
 //   o1(nd);
    if (tree[nd].ff == -1)
        return tree[nd].ss;
    if (curr + tree[nd].ff <= i)
    {
        tree[nd].ss--;
        return query(2 * nd + 1, curr + tree[nd].ff, i);
    }
    else
    {
        tree[nd].ff--;
        return query(2 * nd, curr, i);
    }
}

void sol()
{
    ll n;
    cin >> n;
    a.resize(n);
    iArray(a, n);

    tree.resize(4 * n + 1);
    build(1, 0, n - 1);
    // for(ll i = 0; i < 4*n+1; i++) {
    //     cout << tree[i].ff << ' ' << tree[i].ss << endl;
    // }
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        x--;       
        o1(query(1, 0, x));
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}