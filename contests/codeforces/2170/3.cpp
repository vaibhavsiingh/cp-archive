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
    cin >> n >> k;
    vll q(n), r(n);
    iArray(q,n)   ;
    iArray(r,n);

    sort(all(q));
    sort(all(r));

    ll p1=n-1,p2=0;
    vll sm(n);
    while(p1>=0 && p2<n){
        if(r[p2]>=k) break;
        else if(q[p1]*(r[p2]+1)+r[p2]<=k){
            sm[p1]++;
            p2++;
        }
        else{
            p1--;
        }
    }
    ll count=0;
    vll counted(n);
    for(ll i = n-1; i >=0; i--) {
        ll j=i;
        for(; j>=0 && sm[i]>0; j--){
            if(counted[j]) continue;
            else{
                counted[j]=1;
                sm[i]--;
                count++;
            }
        }
        if(j<0){
            break;
        }
    }

   o1(count);
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