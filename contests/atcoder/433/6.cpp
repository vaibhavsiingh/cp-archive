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

const ll MOD = 998244353;
const ll INF = 2000000 + 2025;
vll factorial;

ll expo(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp = expo(a,b/2);
    ll ans = (temp*temp)%MOD;
    if(b%2==0){
        return ans;
    }
    else{
        return (ans*a)%MOD;
    }
}

long long inverse(ll x){
    return expo(x, MOD-2);
}

long long binomial_coefficient(int n, int k) {
    return factorial[n] * inverse(factorial[k] * factorial[n - k] % MOD) % MOD;
}


void sol(){
    string s;
    cin >> s;
    factorial.reserve(INF+1);
    factorial.emplace_back(1);
    for (int i = 1; i <= INF; i++) {
        factorial.emplace_back(factorial[i - 1] * i % MOD);
    }

    vector<pair<ll,ll>> v;
    ll n = s.length();
    
    for(ll i = 0; i < n; i++) {
        ll len = 1;
        for(ll j=i+1; j<n;){
            if(s[j]==s[i]) j++, len++;
            else break;
        }
        v.push_back({s[i]-'0',len});
        i+=len-1;
    }
    ll k = v.size();
    vector<vll> fwd(k,vll(10)), rvs(k, vll(11));
    fwd[0][v[0].first] = v[0].second;
    for(int i=1; i<k; i++){
        fwd[i] = fwd[i-1];
        fwd[i][v[i].first] = (fwd[i][v[i].first]+v[i].second)%MOD;
    }

    rvs[k-1][v[k-1].first] = v[k-1].second;
    for(int i=k-2; i>=0; i--){
        rvs[i] = rvs[i+1];
        rvs[i][v[i].first] = (rvs[i][v[i].first]+v[i].second)%MOD;
    }

    ll ans = 0;
    for(ll i=0; i<k; i++){
        ll n1 = fwd[i][v[i].first];
        ll m1 = rvs[i][v[i].first+1];
        ll npm = (n1+m1)%MOD;
        ans = (ans+binomial_coefficient(npm, m1))%MOD;
        npm = (npm-v[i].second)%MOD;
        ans = (ans-binomial_coefficient(npm,m1)+MOD)%MOD;
    }

    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}