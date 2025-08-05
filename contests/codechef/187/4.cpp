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
#define DEBUG(x) std::cout << #x << " = " << (x) << std::endl

const ll MOD = 1000000007;
const long long inf = 1e18;       // positive "infinity"
const long long ninf = -1e18;

void sol(){
    ll n,x;
    i2(n,x);
    vll a(n);
    iArray(a,n);
    vll b(n);
    iArray(b,n);
    
    vll best_sum_L(n), best_sum_R(n), best_extra_L(n, ninf), best_extra_R(n, ninf);
    best_sum_L[0] = a[0]; best_sum_R[n-1] = a[n-1];
    if(b[0]==1) best_extra_L[0] = a[0];
    if(b[n-1]==1) best_extra_R[n-1] = a[n-1];

    for(int i=1; i<n; i++){
        if(a[i]>=0){
            best_sum_L[i] = a[i]+max((ll)0,best_sum_L[i-1]);
        }
        else{
            best_sum_L[i] = max(best_sum_L[i-1],a[i]);
        }
        if(b[i]==0){
            best_extra_L[i] = best_extra_L[i-1];
        }
        else{
            best_extra_L[i] = max(best_extra_L[i-1],a[i]);
        }
    }

    for(int i=n-2; i>=0; i--){
        if(a[i]>=0){
            best_sum_R[i] = a[i]+max((ll)0,best_sum_R[i+1]);
        }
        else{
            best_sum_R[i] = max(best_sum_R[i+1],a[i]);
        }
        if(b[i]==0){
            best_extra_R[i] = best_extra_R[i+1];
        }
        else{
            best_extra_R[i] = max(best_extra_R[i+1],a[i]);
        }
    }
    

  ll mn = inf;
    for(int i=1; i<n-1; i++){
        ll initial_sum = best_sum_L[i-1]+best_sum_R[i+1];
        if(initial_sum>=x){
            o1(0);
            return;
        }
        //left
        ll cost_l;
        if(best_extra_L[i-1]>=0){
            cost_l = x-(initial_sum);
        }
        else if(best_sum_L[i-1]>=0){
            cost_l = x-(initial_sum+best_extra_L[i-1]);
        }
        else{
            ll temp_initial_sum = best_extra_L[i-1]+best_sum_R[i+1];
            cost_l = x-(temp_initial_sum);
        }

        //right
        ll cost_r;
        if(best_extra_R[i+1]>=0){
            cost_r = x-(initial_sum);
        }
        else if(best_sum_R[i+1]>=0){
            cost_r = x-(initial_sum+best_extra_R[i+1]);
        }
        else{
            ll temp_initial_sum = best_sum_L[i-1]+best_extra_R[i+1];
            cost_r = x-(temp_initial_sum);
        }
        
        mn = min({mn,cost_l,cost_r})   ;
    }
    o1(mn);
  
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