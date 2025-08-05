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

struct CustomCompare {
    bool operator()(const vll &a, const vll &b) const {
        return tie(a[0], a[1], a[2]) < tie(b[0], b[1], b[2]);
    }
};

void sol(){
    ll n;
    cin >> n;
    vll a(n);
    iArray(a,n);
    set<vll, CustomCompare> s_spot, s_table;
    // for(ll i=0; i<=4*n; i++){
    //     for(ll j=0; i+j<=4*n; j++){
    //         s_spot.insert({3*i+3*j+2, 3*i+1, 3*j+1});
    //         s_spot.insert({3*i+3*j+3, 3*i+1, 3*j+2});
    //         s_spot.insert({3*i+3*j+3, 3*i+2, 3*j+1});
    //         s_spot.insert({3*i+3*j+6, 3*i+2, 3*j+2});
    //         s_table.insert({3*i+3*j+2, 3*i+1, 3*j+1});
    //      //   o2(3*i+1,3*j+1);
    //     }
    // }
    ll curr_sum = -1;

    //o1("");

    for(ll i = 0; i < n; i++) {
        if(s_table.empty()){
            curr_sum++;
            for(ll x=0; x<=curr_sum; x++){
                ll y=curr_sum-x;
                s_spot.insert({3*x+3*y+2, 3*x+1, 3*y+1});
                s_spot.insert({3*x+3*y+3, 3*x+1, 3*y+2});
                s_spot.insert({3*x+3*y+3, 3*x+2, 3*y+1});
                s_spot.insert({3*x+3*y+6, 3*x+2, 3*y+2});
                s_table.insert({3*x+3*y+2, 3*x+1, 3*y+1});
            }
        }
        if(a[i]){
            auto itr = (s_spot.begin());
            vll x = *itr;
            o2(x[1],x[2]);
            s_spot.erase(itr);
            ll tx = 3*(x[1]/3)+1, ty = 3*(x[2]/3)+1;
            vll table = {tx+ty,tx,ty};
            auto itr2 = s_table.find(table);
            if(itr2!=s_table.end()) s_table.erase(itr2);
        }
        else{
            auto itr = (s_table.begin());
            vll x = *itr;
            o2(x[1],x[2]);            
            s_spot.erase(s_spot.find(x));
            s_table.erase(itr);
                    
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