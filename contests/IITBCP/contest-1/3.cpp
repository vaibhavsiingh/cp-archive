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
    ll n,m;
    i2(n,m);
    vll a(n);
    iArray(a,n);
    ll n2;
    cin >> n2;
    vll b(n2);
    iArray(b,n2);
    vector<pll> fa;
    for(int i=0; i<n; i++){
        int count = 1;
        while(a[i]%m==0){
            count*=m;
            a[i]/=m;
        }
        fa.push_back({a[i],count});
    }
    
    vector<pll> fb;
    for(int i=0; i<n2; i++){
        int count = 1;
        while(b[i]%m==0){
            count*=m;
            b[i]/=m;
        }
        fb.push_back({b[i],count});
    }
    ll p1=0,p2=0;
    int curr = -1, num = -1;
    while(p1<n && p2<n2){
        if(curr==-1){
            curr = fa[p1].first;
            num = fa[p1].second;
            
        }
       // o2(fa[p1].first, fa[p1].second);
       // o2(fb[p2].first, fb[p2].second);
        if(fb[p2].first!=curr){
            o1("No");
            return;
        }
        if(num>fb[p2].second){
            //cout << "1\n";
            num -= fb[p2].second;
            p2++;
        }
        else if(num==fb[p2].second){
            //cout << "2\n";
            curr = -1;
            p1++;
            p2++;
        }
        else{
            //cout << "3\n";
            p1++;
            fb[p2].second -= num;
            curr=-1;
        }
    }
    if(p1<n || p2<n2){
        o1("No");
        return;
    }
    o1("Yes");
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