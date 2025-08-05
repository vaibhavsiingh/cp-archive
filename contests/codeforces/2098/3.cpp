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
    vll a(n);
    iArray(a,n);
    unordered_map<ll,ll> m;
    for(ll i = 0; i < n; i++) {
        m[a[i]]++;        
    }
    for(ll i = 0; i < n; i++) {
        if(m[a[i]]>=4){
            o1("YES");
            return;
        }
        if(m[a[i]]==3){
            m[a[i]]=2;
        }
    }
    vector<ll> ue;
    unordered_set<ll> seen;
    for (ll x : a) {
        if (seen.find(x) == seen.end()) {
            ue.push_back(x);
            seen.insert(x);
        }
    }
    sort(ue.begin(),ue.end());
    unordered_map<ll,ll> winning;
    winning[ue[0]]=m[ue[0]]/2;
    for(ll i = 1; i < n; i++) {
        ll curr_day=ue[i];
        if(winning[curr_day-1]==1){
            if(m[curr_day]==2){
                o1("YES");
                return;
            }
            else{
                winning[curr_day]=1;
            }
        }
        else{
            winning[curr_day] = m[curr_day]/2;
        }
    }
    o1("NO");
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