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
#define iArray(a, n) for (ll ajkbbkdv = 0; ajkbbkdv < n; ajkbbkdv++) cin >> a[ajkbbkdv];
#define i2(a, b) cin >> a >> b;
#define oArray(a, n) for (ll kajsbabk = 0; kajsbabk < n; kajsbabk++) cout << a[kajsbabk] << ' '; cout << endl;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, n) for (int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n,m;
    i2(n,m);

    vector<vector<ll>> seqs(n);

    for(ll j = 0; j < n; j++) {
        int li;
        cin >> li;
        seqs[j].resize(li);        
        iArray(seqs[j], li);        
        sort(all(seqs[j]));
    }
    
    vll mex1(n,-1), mex2(n,-1);
    for(int i=0; i<n; i++){
        int num = 0;
        int ptr = 0;
        
        while(ptr < seqs[i].size()){
            if(seqs[i][ptr] < num) ptr++;
            else if(seqs[i][ptr] == num) ptr++, num++;
            else{
                if(mex1[i] == -1){
                    mex1[i] = num;
                    num++;                    
                }
                else{
                    mex2[i] = num;
                    break;
                }
            }
        }
        if(mex1[i] == -1){
            mex1[i] = num;
            mex2[i] = num+1;
        }
        else if(mex2[i] == -1){
            mex2[i] = num;
        }
    }

    ll mx = *max_element(all(mex2));
    if(mx > m){
        o1((m+1)*mx);
    }
    else{
        ll ans = 0;
        ans += (m*(m+1))/2;
        ans -= (mx*(mx+1))/2;
        ans += (mx*(mx+1));
        o1(ans);
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
    return 0;
}