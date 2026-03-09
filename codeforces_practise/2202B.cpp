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
#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;


void sol(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1;
    for(int i=0; i<n; i+=2){
        s1.push_back('a');
        if(i+1<n) s1.push_back('b');
    }
   // o1(s1);

    ll l=0, r=n-1;
    for(int i=0; i<n; i++){
        if(s[i]=='?'){
            if(i==n-1) continue;
            if(s1[l]==s1[r]) s[i] = s1[l], l++;
            else {
                if(s[i+1]=='?'){
                    i++;
                    l+=2;
                }
                else{
                    if(s[i+1]=='b') {
                        if(s1[l]=='a') l++;
                        else if(s1[r]=='a') r--;                        
                    }
                    else if(s[i+1]=='a'){
                        if(s1[l]=='b') l++;
                        else if(s1[r]=='b') r--;  
                    }
                }
            }
        }
        else{
            if(s1[l]==s[i]) l++;
            else if(s1[r]==s[i]) r--; 
            else{
                o1("NO");
                return;
            }
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
    return 0;
}