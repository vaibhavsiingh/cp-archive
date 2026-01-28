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

int check(vector<ll> a){
    int n= a.size();
    int gcd = -1;
    for(int i=0; i<n-1; i++){
        ll g = __gcd(a[i],a[i+1]);
        if(g<gcd) return i;
        gcd=g;
    }
    return -1;
}

void sol(){
    ll n;
    cin >> n;
    vector<ll> a(n,0);
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ansMaybe =check(a);
    if(ansMaybe==-1){
        o1("YES");
        return;
    }
    vector<ll> seq1,seq2,seq3;
    for(int i=0; i<n; i++){
        if(i!=ansMaybe-1) seq1.pb(a[i]);
        if(i!=ansMaybe) seq2.pb(a[i]);
        if(i!=ansMaybe+1) seq3.pb(a[i]);
    }
    ansMaybe  =check(seq1);
    if(ansMaybe==-1){
        o1("YES");
        return;
    }
    ansMaybe  =check(seq2);
    if(ansMaybe==-1){
        o1("YES");
        return;
    }
    ansMaybe  =check(seq3);
    if(ansMaybe==-1){
        o1("YES");
        return;
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