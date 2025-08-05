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
    ll n,m;
    i2(n,m);
    vll b(n);
    iArray(b,n);
    vll w(m);
    iArray(w,m);
    sort(b.rbegin(),b.rend());
    sort(w.rbegin(),w.rend());
    ll ptr1=0,ptr2=0;
    ll ans=0;
    while(ptr1<n && b[ptr1]>=0){
        ans+=b[ptr1];
        ptr1++;
    }
    if(ptr1==n){
        while(ptr2<n && ptr2<m && w[ptr2]>=0){
            ans+=w[ptr2];
            ptr2++;
        }
        o1(ans);
        return;
    }
    while(ptr2<ptr1 && ptr2<m && w[ptr2]>=0){
        ans+=w[ptr2];
        ptr2++;
    }
    if(ptr2==m){
        o1(ans);
        return;
    }
    if(w[ptr2]<0){
        o1(ans);
        return;
    }
    while(ptr1<n && ptr2 <m && b[ptr1]+w[ptr2]>0){
        ans+=b[ptr1]+w[ptr2];
        ptr1++;
        ptr2++;
    }
    
    o1(ans);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}