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

void sol(){
    ll n,k;
    i2(n,k);
    k--;
    vll ans(n+1); 
    ll i=n-1;
    while(k>0 && i>0){
        if(k&1) ans[i] = 1;
        k>>=1;
        i--;
    }
    if(k>0){
        o1(-1);
        return;
    }
    vll act_ans(n);
    ll curr_num=1;
    ll p1=0,p2=n-1;
    for(;curr_num<=n; curr_num++){
        if(ans[curr_num]){
            act_ans[p2] = curr_num;
            p2--;
        }
        else act_ans[p1] = curr_num, p1++;
    }
    oArray(act_ans,n);
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
    return 0;
}