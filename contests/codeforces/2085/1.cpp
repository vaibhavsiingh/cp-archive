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
ll n,k;

bool check_palindrome(string s1, string s2){
    for(ll i = 0; i < n; i++) {
        if(s1[i]!=s2[i]) return false;
    }
    return true;
}

bool s1smallers2(string s1, string s2){
    for(ll i=0; i<n; i++){
        if(s1[i]==s2[i]) continue;
        else return s1[i] < s2[i];
    }
    o1("DEBUG");
    return false;
}

void sol(){
    
    i2(n,k);
    string s1,s2;
    cin >> s1;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    if(check_palindrome(s1,s2)){
        if(k==0){
            o1("NO");
            return;
        }
        char c1 = s1[0];
        bool all_same = true;
        for(ll i=1; i<n; i++){
            if(s1[i]!=c1){
                all_same = false;
                break;
            }
        }
        if(all_same){
            o1("NO");
            return;
        }
        else{
            o1("YES");
            return;
        }
    }
    else{
        if(k>0){
            o1("YES");
            return;
        }
        else{
            if(s1smallers2(s1,s2)){
                o1("YES");
                return;
            }
            else{
                o1("NO");
                return;
            }
        }
    }
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