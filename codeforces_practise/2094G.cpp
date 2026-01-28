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
    ll q;
    cin >> q;
    deque<ll> d;
    ll sz = 0;
    ll reversed = 0;
    ll sum=0;
    ll ans=0, ans_rev=0;
    while(q--){
        ll s;
        cin >> s;
        if(s==1){
            if(reversed){
                ll temp = sum - d.size()*d.front();
                ans_rev += sum - d.size()*d.front();
                ans -= temp;
                temp = d.front();
                d.pop_front();
                d.push_back(temp);
                o1(ans_rev);
            }
            else{
                ll temp = sum - d.size()*d.back();
                ans += sum - d.size()*d.back();
                ans_rev -= temp;
                temp = d.back();
                d.pop_back();
                d.push_front(temp);
                o1(ans);
            }
        }
        else if(s==2){
            reversed ^= 1;
            if(reversed) o1(ans_rev);
            else o1(ans);
        }
        else{
            ll k;
            cin >> k;
            if(reversed){
                d.push_front(k);
                ans_rev += (d.size()*k);
                ans += sum + k;
                sum += k;
                o1(ans_rev);
            }
            else{
                d.push_back(k);
                ans += (d.size()*k);
                ans_rev += sum + k;
                sum += k;
                o1(ans);
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