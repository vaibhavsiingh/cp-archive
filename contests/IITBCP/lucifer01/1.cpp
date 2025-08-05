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
    vector<string> v;
    unordered_map<char,int> m;
    m['q'] = 9;
    m['r'] = 5;
    m['p'] = 1;
    m['k'] = 0;
    m['b'] = 3;
    m['n'] = 3;
    ll b=0,w=0;
    for(int i=0; i<8; i++){
        string s;
        cin >> s;
        for(ll i = 0; i < 8; i++) {
            if(s[i]!='.'){
                if(s[i]<'a'){
                    w+=m[s[i]+32];
                }
                else{
                    b+=m[s[i]];
                }
            }
        }
    }
    if(w>b){
        o1("White");
    }
    else if(w<b){
        o1("Black");
    }
    else o1("Draw");
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}