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
    ll n,k;
    i2(n,k);
    vll a(n);
    iArray(a,n);
    vll b = a;
    sort(all(b));
    if(k==1){
        o1("YES");
        return;
    }
    ll bt=0;
    for(int i=k-1; (i<n&&b[i]==b[k-2]); i++) bt++;
    ll bt_ele = b[k-2];
    vll good_a;
    for(int i=0; i<n; i++){
        if(a[i]<=bt_ele){
            good_a.pb(a[i]);
        }
    }
    ll p1=0,p2=good_a.size()-1;
    if(bt==0){
        while(p1<p2){
            if(good_a[p1]!=good_a[p2]){
                o1("NO");
                return;
            }
            p1++;
            p2--;
        }
        o1("YES");
        return;
    }
 //   oArray(good_a,good_a.size());
    while(p1<p2){
   //     o2(p1,p2);
        if(good_a[p1]==good_a[p2]){
            p1++;
            p2--;
        }
        else{
            if(good_a[p1]==bt_ele || good_a[p2]==bt_ele){
                if(bt>0){
                    if(good_a[p1]==bt_ele){
                        p1++;
                    }
                    else p2--;
                    bt--;
                }
                else{
                    o1("NO");
                    return;
                }
            }
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