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
    int n;
    cin >> n;
    int a[n];
    iArray(a,n);
    stack<int> elements_not_appearing;
    unordered_set<int> s,temp;
    for(int i=0; i<n; i++){
        temp.insert(a[i]);
    }
    for(int i=1; i<=n; i++){
        if(!temp.count(i)) elements_not_appearing.push(i);
    }
    int b[n];
    for(int i=0; i<n; i++){
        if(s.count(a[i])){
            b[i] = elements_not_appearing.top();
            elements_not_appearing.pop();
        }
        else{
            b[i] = a[i];
            s.insert(a[i]);
        }
    }
    oArray(b,n);
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