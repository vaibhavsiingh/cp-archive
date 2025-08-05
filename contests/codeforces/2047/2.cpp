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
    vector<int> count(26);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> place(26,-1);
    for(int i=0; i<n; i++){
        count[s[i]-'a']++;
        place[s[i]-'a'] = i;
    }
    int mx = -1, mn = n+1, mxPos = -1, mnPos = -1;
    for(int i=0; i<26; i++){
        if(count[i]==0) continue;
        if(mx < count[i]){
            mx =  count[i];
            mxPos = place[i];
        }
        if(mn >= count[i]){
            mn =  count[i];
            mnPos = place[i];
        }
    }
    s[mnPos] = s[mxPos];
    o1(s);

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