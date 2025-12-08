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
    
    ll n, k,q;
    cin >> n >> k >> q;
    vector<pll> mex;
    vector<pll> mn;

    vll nums(n,-1), mark(n,0);
    

    for(ll i = 0; i < q; i++) {
        ll c,l,r;
        cin >> c >> l >> r;
        l--;r--;
        if(c==1){
            mn.push_back({l,r});
        }
        else{
            mex.push_back({l,r});
        }
        for(ll i=l; i<=r; i++) mark[i] |= c;
    }

    sort(all(mex));
    for(ll i=0; i<n; i++){
        if(mark[i]==1){
            nums[i] = k;
        }
        else if(mark[i]==3){
            nums[i] = k+1;
        }
    }
    
    for(auto [l,r]: mex){
        vll pres(k);
        for(ll i = l; i <= r; i++) {
            if(nums[i]<k && nums[i]!=-1) pres[nums[i]]++;
        }        
        
        ll i=0,j=l;
    
        while(i<k){
            if(pres[i]) {
                i++;
                continue;
            }
            while(j<= r && nums[j]!=-1){
                j++;
            }
            // if(j>=n){
            //     reach;
            // }
            nums[j] = i;
            j++;
            i++;
        }        

    }    

    for(ll i = 0; i < n; i++) {
        if(nums[i]==-1) nums[i]=k+1;
    }

    oArray(nums,n);

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