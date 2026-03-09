#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;

#define o1(a) cout << a << "\n"

const int MAXN = 30;
ll C[MAXN + 1][MAXN + 1];

void precompute() {
    for (int n = 0; n <= MAXN; n++) {
        C[n][0] = C[n][n] = 1;
        for (int r = 1; r < n; r++) {
            C[n][r] = C[n-1][r-1] + C[n-1][r];
        }
    }
}

void sol(){
    ll n,k;
    cin >> n >> k;

    ll d = -1;
    ll tmp = n;
    while(tmp > 0){
        d++;
        tmp >>= 1;
    }

    if(d == 0){
        if(k >= 1) o1(0);
        else o1(1);
        return;
    }
    
    if(k >= 2*d - 1){
        ll win_ans = 0;
        if(d + 1 > k) win_ans++;
        o1(win_ans);
        return;
    }

    ll win_ans = 0;

    for(ll n0 = 0; n0 <= d-1; n0++){
        for(ll n1 = 0; n0 + n1 <= d-1; n1++){
            ll cost = 1 + n0 + 2*n1;            
            if(cost <= k){
                win_ans += C[n0 + n1][n1];
            }
        }
    }
    
    if(d + 1 <= k) win_ans++;
    o1(n - win_ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();  

    ll t;
    cin >> t;
    while(t--) sol();

    return 0;
}