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


ll count_equal(const vector<ll>& a, ll x) {
    auto p = equal_range(a.begin(), a.end(), x);
    return p.second - p.first;
}

pair<ll,ll> mex(const vector<ll>& A) {
    ll m1 = 0;
    ll i = 0;
    ll n = A.size();
    
    while (i < n) {
        if (A[i] == m1) {
            m1++;
        } else if (A[i] > m1) {
            break;
        }
        i++;
    }
    ll m2 = m1 + 1;
    while (i<n){
        if (A[i]==m2){
            m2++;
        }
        i++;
    }
    return {m1, m2};
}

void sol(){
    ll n;
    cin >> n;
    vll l(n)   ;
    vector<vll> mat(n);
    vll a;
    vll mex1(n);
    vll mex2(n);
    for(ll i=0; i<n; i++){
        cin >> l[i];
        mat[i].resize(l[i]);
        for(ll j = 0; j < l[i]; j++) {             
            cin >> mat[i][j];
            a.pb(mat[i][j]);
        }        
        sort(all(mat[i]));
        tie(mex1[i], mex2[i]) = mex(mat[i]);        
    }
    sort(all(a));
    ll sm = accumulate(all(l),0);
    ll ans = 0;

    for(ll i = 0; i < n; i++) {
        ans += (sm-l[i])*(n-2)*mex1[i];
        for(ll j=0; j<l[i]; j++)  {
            bool same_neighbor = false;
            if (j > 0 && mat[i][j-1] == mat[i][j]) same_neighbor = true;
            if (j + 1 < l[i] && mat[i][j+1] == mat[i][j]) same_neighbor = true;

            if (same_neighbor) {
                ans += (n-1) * mex1[i];
            } else {
                ans += (mat[i][j] < mex1[i]) ? (n-1) * mat[i][j] : (n-1) * mex1[i];
            }
        }
        ll x = count_equal(a,mex1[i]);
        ans += x*mex2[i] + (sm-l[i]-x)*mex1[i];

    }
    o1(ans);

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