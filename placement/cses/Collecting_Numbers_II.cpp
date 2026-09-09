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
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n, m;
    cin >> n >> m;
    vll a(n);
    iArray(a,n);
    vll pos(n+1,INF);
    pos[0] = -1;
    ll cnt = 1;
    for(ll i = 0; i < n; i++) {
        if(pos[a[i]-1] > i){
            cnt++;
        }
        pos[a[i]] = i;
    }

    while(m--){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;

        set<ll> problametic_nums = {a[x], a[y]};
        if(a[x]+1 <=n) problametic_nums.insert(a[x]+1);
        if(a[y]+1 <=n) problametic_nums.insert(a[y]+1);

        for(ll num : problametic_nums){
            if(pos[num-1] < pos[num])cnt++;
        }

        pos[a[x]] = y;
        pos[a[y]] = x;
        swap(a[x], a[y]);

        for(ll num : problametic_nums){
            if(pos[num-1] < pos[num])cnt--;
        }
        
        o1(cnt);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}