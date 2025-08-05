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

const ll MOD = 1000000007;

void sol(){
    ll n,m;
    i2(n,m);
    vll a(n+1);
    iArray(a,n);
    a.insert(a.begin(),0);
    vll v(n+1);
    ll ans = 1;
    for(int i=1; i<=n; i++){
        v[a[i]] = i;
    }
    for(int i=1; i<n; i++){
        ans += (v[i+1]<v[i]);
    }
    while(m--){
        ll l,r;
        i2(l,r);
        set<pll> s;
        if(a[l]-1>0){
            s.insert({a[l]-1,a[l]});
        }
        if(a[r]-1>0){
            s.insert({a[r]-1,a[r]});
        }
        if(a[l]+1<=n){
            s.insert({a[l],a[l]+1});
        }
        if(a[r]+1<=n){
            s.insert({a[r],a[r]+1});
        }
        for(auto itr:s){
            ans -= (v[itr.first]>v[itr.ss]);
        }
        swap(a[l],a[r]);
        v[a[l]] = l;
        v[a[r]] = r;

        for(auto itr:s){
            ans += (v[itr.first]>v[itr.ss]);
        }
        o1(ans);

    }

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}