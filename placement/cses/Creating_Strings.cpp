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

void cs(vector<ll>& freq, string& curr, vector<string>& ans, int idx, ll n){
   // o2("curr",curr)
    if(idx == n){
        ans.push_back(curr);
        return;
    }
    for(ll i=0; i<26; i++){
        if(freq[i] > 0){
            curr.push_back('a'+i);
            freq[i]--;
            cs(freq, curr, ans, idx+1, n);
            freq[i]++;
            curr.pop_back();
        }
    }
}

void sol(){
    string s;
    cin >> s;
    vector<ll> freq(26);
    for(char c: s) freq[c-'a']++;

    string curr = ""   ;
    vector<string> ans;
    cs(freq, curr, ans, 0, s.size());
    o1(ans.size());

    for(string& string_s: ans) o1(string_s);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}