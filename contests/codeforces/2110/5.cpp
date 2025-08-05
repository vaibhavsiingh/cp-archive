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

const ll MOD = 1000000007;
const ll INF = 1e18;




void sol(){
    ll n;
    cin >> n;
    map<ll,map<ll,ll>> m;
    map<ll,map<ll,ll>> mp;
    map<ll,ll> deg;
    for(int i=0; i<n; i++){
        ll x,y;
        i2(x,y);
        m[x][-y] = 1;
        m[-y][x] = 1;
        mp[x][-y] = i+1;
        mp[-y][x] = i+1;
        deg[x]++;
        deg[-y]++;
    }



    ll v1=0,v2=0, bad=0;
    for(auto [nd,d]:deg){
        if(d&1){
            if(v1==0){
                v1 = nd;
            }
            else if(v2==0){
                v2 = nd;
            }
            else{
                bad=1;
                break;
            }
        }
        if(d==0){
            bad=1;
            break;
        }
    }

    //o2(v1,v2);
    if(v1!=0 && v2==0) bad = 1;

    if(bad){
        o1("NO");
        return;
    }


    if(v1!=0){
        m[v1][v2]++;
        m[v2][v1]++;
    }

    ll first = m.begin()->first;

    stack<ll> stk;
    stk.push(first);
    vll res;
    while(!stk.empty()){
        ll x = stk.top();
        ll added = 0;
        for(auto [c,d]:m[x]){
            if(d){
                m[x][c]--;
                m[c][x]--;
                stk.push(c);
                added=1;
                break;
            }
        }
        if(!added){
            stk.pop();
            res.pb(x);
        }
    }

   // oArray(res, res.size());

    for(auto [x,mep]:m){
        for(auto [y,d]:mep){
            if(d) bad = 1;
        }
    }

    if(bad){
        o1("NO");
        return;
    }

//    oArray(res,res.size());

    if(v1!=0){
        for(ll i=0; i+1<res.size(); i++){
            if((res[i]==v1 && res[i+1]==v2)||(res[i]==v2 && res[i+1]==v1)){
                vll res2;
                for(ll j=i+1; j<res.size(); j++){
                    res2.pb(res[j]);
                }
                for(ll j=1; j<=i; j++){
                    res2.pb(res[j]);
                }
                res = res2;
                break;
            }

        }
    }

  //  oArray(res,res.size());
    o1("YES");
    for(ll i = 0; i < n; i++) {
        cout << mp[res[i]][res[i+1]] << ' ';
    }
    cout << '\n';
  



    
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