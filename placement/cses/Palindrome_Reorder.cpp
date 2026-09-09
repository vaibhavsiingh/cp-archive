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

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    string s;
    cin >> s;
    
    vector<ll> frq(26);
    
    for(char c: s){
        frq[c-'A']++;
    }
    
    ll odd = -1;
    string ret;
    for(ll i=0; i<26; i++){

        if(frq[i]%2!=0){            
            if(odd != -1){
                o1("NO SOLUTION");
                return;
            }
            else odd = i;
        }

        for(ll j=0; j<frq[i]/2; j++){
            ret.push_back('A'+i);
        }
    }
    
    string cop = ret;
    if(odd!=-1) ret.push_back('A'+odd);

    reverse(cop.begin(), cop.end());

    ret += cop;
    o1(ret);

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}