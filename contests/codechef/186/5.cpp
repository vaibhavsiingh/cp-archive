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

vll f(ll n, ll k){
    if(n==0){
        if(k==1)return {1};
        else if(k==0) return {0};
        else return {-1};
    }
    else{
        ll total_nodes_in_larger_tree = (1<<(n+1))-1;
        if(k==total_nodes_in_larger_tree){
            vll a((1<<n),1);
            return a;
        }
        ll total_nodes_in_smaller_tree = (1<<(n))-1;
        if(k==total_nodes_in_smaller_tree){
            vll a1(1<<n);
            for(int i=0; i<(1<<(n-1)); i++){
                a1[i] = 1;
            }
            return a1;
        }
        ll mx_possible_in_smaller_tree=(total_nodes_in_smaller_tree-(n));
        ll temp = min(k,mx_possible_in_smaller_tree);
        vll a1 = f(n-1,temp);
        vll a2 = f(n-1,k-temp);
        for(auto x:a2){
            a1.pb(x);
        }
        return a1;
    }
}


void sol(){
    ll n,k;
    i2(n,k);
    ll total_nodes = (1<<(n+1))-1;
    if(k==total_nodes){
        vll a((1<<n),1);
        o1("Yes");
        for(auto x:a){
           cout << x;
        }
        o1("");
        return;
    }
    if(k>total_nodes-(n+1)){
        o1("No");
        return;
    }
    vll ans = f(n,k);
    o1("Yes");
    for(auto x:ans){
        cout << x;
    }
    o1("");
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