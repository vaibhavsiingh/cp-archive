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
    ll n;
    cin >> n;

    ll mx = (1<<n);
    vll done(mx+1);

    string s;
    for(ll i = 0; i < n; i++) {
        s.push_back('0');
    }
    o1(s);
    done[0]++;

    auto findNext = [&](string start){
        ll num = 0;
        for(ll c: start){
            num = num << 1;
            if(c=='1'){
                num += 1;
            }
        }
        for(ll i=0; i<n; i++){
            ll new_num = num ^ (1<<i);
            if(done[new_num]){
                continue;
            }
            else{
                done[new_num] = true;
                return n-1-i;
            }            
        }
        return (ll)-1;
    };

    ll cnt = 1;
    while(cnt < mx){
        ll idx = findNext(s);
        if(s[idx] == '1') s[idx] = '0';
        else s[idx] = '1';

        o1(s);
        cnt++;
    }
    

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}