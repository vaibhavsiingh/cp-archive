#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef complex<ll> P;


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

struct Seg {
    bool ok;  
    int len;  
    ll f, l;  
    ll d_first, d_last;  
};


Seg makeSeg(ll x) {
    Seg s;
    s.ok = true;
    s.len = 1;
    s.f = s.l = x;
    
    return s;
}


Seg mergeSeg(const Seg &S, const Seg &T) {
    Seg X;
    
    if (!S.ok || !T.ok) {
        X.ok = false;
        return X;
    }
    
    if (S.l >= T.f) {
        X.ok = false;
        return X;
    }
    
    
    ll b = T.f - S.l;
    
    
    if (S.len >= 2 && !(S.d_last < b)) {
        X.ok = false;
        return X;
    }
    
    if (T.len >= 2 && !(b < T.d_first)) {
        X.ok = false;
        return X;
    }
    
    if (S.len >= 2 && T.len >= 2) {
        if (!((b - S.d_last) < (T.d_first - b))) {
            X.ok = false;
            return X;
        }
    }
    
    
    X.ok = true;
    X.len = S.len + T.len;
    X.f = S.f;
    X.l = T.l;
    
    
    
    if (S.len >= 2)
        X.d_first = S.d_first;
    else
        X.d_first = b;
    
    
    
    if (T.len >= 2)
        X.d_last = T.d_last;
    else
        X.d_last = b;
        
    return X;
}

void sol(){
    int n;
    cin >> n;
    vll A(n);
    rep0(i, n) cin >> A[i];
    
    
    if(n == 1){
        
        cout << "1\n";
        return;
    }
    
    
    vector<Seg> prefix(n);
    prefix[0] = makeSeg(A[0]);
    for (int i = 1; i < n; i++) {
        
        Seg cur = makeSeg(A[i]);
        
        prefix[i] = mergeSeg(prefix[i-1], cur);
    }
    
    
    vector<Seg> suffix(n);
    suffix[n-1] = makeSeg(A[n-1]);
    for (int i = n - 2; i >= 0; i--) {
        Seg cur = makeSeg(A[i]);
        
        suffix[i] = mergeSeg(cur, suffix[i+1]);
    }
    
    rep0(i, n){
        Seg merged;
        if(i == 0){            
            merged = suffix[1];
        } else if(i == n-1){            
            merged = prefix[n-2];
        } else {            
            merged = mergeSeg(prefix[i-1], suffix[i+1]);
        }
        cout << (merged.ok ? "1" : "0");
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
