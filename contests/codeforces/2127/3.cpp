#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
#define iArray(a, n) for (ll _i = 0; _i < n; _i++) cin >> a[_i]
#define o1(a) cout << a << "\n"

const ll INF = (ll)4e18;

inline ll compute_delta(ll ai, ll aj, ll bi, ll bj) {
    
    ll v[4] = { ai, aj, bi, bj };
    sort(v, v+4);
    ll orig = llabs(ai - bi) + llabs(aj - bj);
    ll best = (v[3] - v[0]) + (v[2] - v[1]);
    ll d = best - orig;
    return d > 0 ? d : 0;
}

void sol(){
    ll n, k;
    cin >> n >> k;
    vll a(n), b(n);
    iArray(a, n);
    iArray(b, n);

    
    ll V0 = 0;
    vll d(n);
    for(ll i = 0; i < n; i++){
        V0 += llabs(a[i] - b[i]);
        d[i] = a[i] - b[i];
    }
    
    if(k == 0 || n < 2) {
        o1(V0);
        return;
    }

    
    vector<pair<ll,int>> ordD(n), ordA(n), ordB(n);
    for(int i = 0; i < n; i++){
        ordD[i] = { d[i], i };
        ordA[i] = { a[i], i };
        ordB[i] = { b[i], i };
    }
    sort(ordD.begin(), ordD.end());
    sort(ordA.begin(), ordA.end());
    sort(ordB.begin(), ordB.end());

    
    auto scan_neigh = [&](const vector<pair<ll,int>>& ord){
        ll best = INF;
        for(int t = 0; t+1 < n; t++){
            int i = ord[t].second;
            int j = ord[t+1].second;
            ll x = compute_delta(a[i], a[j], b[i], b[j]);
            if(x < best) {
                best = x;
            }
        }
        return best;
    };

    ll bestD = scan_neigh(ordD);    
    ll bestA = scan_neigh(ordA);
    ll bestB = scan_neigh(ordB);
    ll minDelta = min({bestD, bestA, bestB});

    
    o1(V0 + minDelta);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--) sol();
    return 0;
}
