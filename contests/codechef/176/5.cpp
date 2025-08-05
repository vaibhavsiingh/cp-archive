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

vector<int> prime_list = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};


void sol(){
    ll n;
    cin >> n;
    vll v(n);
    iArray(v,n);
    vll mex_p(n);
    vector<vll> adj(n);
    for(ll i=0; i<n-1; i++){
        ll x,y;
        i2(x,y);
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    // for(ll i=0; i<n; i++){
    //     o1(i);
    //     for(ll j:adj[i]){
    //         cout << j << ' ';
    //     }
    //     o1("");
    // }
    // o1("");


    
    for(ll i = 0; i < n; i++) {
        for(ll pr:prime_list){
            if(v[i]%pr>0) {
                mex_p[i]=pr;
                break;
            }
        }
    }

    for(ll i=0; i<n; i++){
        vll visited(n,0);
        queue<pll> q;
        ll ans =0;
        q.push({mex_p[i],i});
        visited[i]  = 1;
        while(!q.empty()){
            auto [mex,nd] = q.front();
            q.pop();
          //  o2(i,nd);
           // o1(mex);
            ans += mex;
            for(ll chd:adj[nd]){
                if(!visited[chd]){
        //            o2("Added to q", chd);
                    q.push({min(mex,mex_p[chd]),chd});
                    visited[chd] = 1;
                }
            }
        }
        cout << ans << ' ';

    }
    o1("");
 //   o1("");
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