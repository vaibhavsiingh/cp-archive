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

const ll MOD = 1000000007;

ll solve(int n, vll& cost, vector<vll>& allowed){
    ll dp0 = 0, dp1 = cost[0];
    for(int i=0; i<n-1; i++){
        ll new_dp0 = LLONG_MAX, new_dp1 = LLONG_MAX;
        for(int prev =0; prev<2; prev++){
            ll dp_prev = (prev) ? dp1 : dp0;
            if(dp_prev == LLONG_MAX) continue;
            for(ll curr =0; curr<2; curr++){
                ll d = curr - prev +1;
                if(!allowed[i][d]) continue;
                ll c = dp_prev;
                if(curr) c+= cost[i+1];
                if(curr) new_dp1 = min(new_dp1,c);
                else new_dp0 = min(new_dp0,c);
            }
        }
        dp0 = new_dp0;
        dp1 = new_dp1;
    }
    return min(dp0,dp1);
}

void sol(){
    ll n;
    cin >> n;
    vector<vll> h(n,vll(n)) ;
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<n; j++){
            cin >> h[i][j];
        }
    }

    vll a(n), b(n);
    iArray(a,n);
    iArray(b,n);
    vector<vll> allowed_x(n,vll(3,1)),  allowed_y(n,vll(3,1));
    for(ll i = 0; i < n-1; i++) {
        for(ll j=0; j<n; j++){
            ll diff = h[i][j]-h[i+1][j];
            if(diff==-1) allowed_x[i][0] = false;
            else if(diff==0) allowed_x[i][1] = false;
            else if(diff==1) allowed_x[i][2] = false;
        }
    }

    for(ll j = 0; j < n-1; j++) {
        for(ll i=0; i<n; i++){
            ll diff = h[i][j]-h[i][j+1];
            if(diff==-1) allowed_y[j][0] = false;
            else if(diff==0) allowed_y[j][1] = false;
            else if(diff==1) allowed_y[j][2] = false;
        }
    }

    ll best_rows = solve(n,a,allowed_x);
    ll best_cols = solve(n,b,allowed_y);
    if(best_rows==LLONG_MAX || best_cols == LLONG_MAX){
        o1(-1);
    }
    else o1(best_cols+best_rows);
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