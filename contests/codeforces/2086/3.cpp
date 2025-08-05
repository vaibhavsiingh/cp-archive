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

void sol(){
    ll n;
    cin >> n;
    vll p(n+1),d(n);
    for(ll i = 1; i < n+1; i++) {
        cin >>p[i] ;
    }
    for(ll i = 0; i < n; i++) {
        cin >> d[i];
    }
    vll visited(n+1);
    vll comp(n+1);
    vll size(n+1);
    for(ll i=1; i<=n; i++){
        if(!visited[i]){
            ll curr = i;
            ll size_comp = 0;
            while(!visited[curr]){
                visited[curr] = 1;
                comp[curr] = i;
                curr = p[curr];
                size_comp++;
            }
            size[i] = size_comp;
        }
    }

    vll pp(n+1);
    vll ans;
    ll ans_rn = 0;
    for(ll i = 0; i < n; i++) {
        if(pp[comp[d[i]]]){
            ans.push_back(ans_rn);
        }
        else{
            pp[comp[d[i]]] = 1;
            ans_rn += size[comp[d[i]]];
            ans.push_back(ans_rn);   
        }
    }
    oArray(ans,n);

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