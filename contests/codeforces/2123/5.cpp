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
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);

    vll freq(n+1), ans(n+1);
    for(ll i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    int start =0;
    while(freq[start]!=0) start++;
    ll faltu = 0;
  //  cout << "start: " << start << endl;
    for(int i=0; i<start; i++) faltu += freq[i]-1;
    for(int i=start+1; i<=n; i++) faltu += freq[i];
    if(faltu==n){
        for(ll i = 0; i < n+1; i++) {
            cout << 1 << ' ';
        }
        cout <<'\n';
        return;
    }
   // cout << "faltu: " << faltu << endl;
    ans[faltu]++;
    for(int i=start-1; i>=0; i--){
        ans[faltu+1]+=1;
        //cout << "+1 at " << faltu << endl;
        ans[freq[i]-1]--;
        //cout << "-1 at " << freq[i]-1 << endl;        
        faltu++;
    }
    ll temp=0;
    for(ll i = n; i>=0; i--) {
        temp += ans[i];
        ans[i] = temp;
    }
    oArray(ans,n+1);
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