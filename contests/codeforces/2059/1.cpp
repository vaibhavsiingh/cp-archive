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
    unordered_set<int> s1,s2;
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    iArray(a,n);
    iArray(b,n);
    for(int i=0; i<n; i++){
        s1.insert(a[i]);
        s2.insert(b[i]);
    }
    int n1 = s1.size(),n2 =s2.size();
    if(n1 < n2){
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    if(n2==1){
        if(n1<3){
            o1("NO");
            return;
        }
    }
    o1("YES");
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