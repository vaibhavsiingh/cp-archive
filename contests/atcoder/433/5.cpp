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

    vll x(n),y(m);
    iArray(x,n);
    iArray(y,m);

    unordered_map<ll,ll> m_x,m_y;
    for(ll i = 0; i < n; i++) {
        if(m_x[x[i]]!=0){
            o1("No");
            return;
        }
        m_x[x[i]] = i+1;
    }

    for(ll i = 0; i < m; i++) {
        if(m_y[y[i]]!=0){
            o1("No");
            return;
        }
        m_y[y[i]] = i+1;
    }    

    ll nm = n*m;
    vector<vector<pll>> ok_to_fill(nm+1);
    queue<pll> q;

    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<m; j++){
            ok_to_fill[min(x[i],y[j])].push_back({i,j});
        }
    }    

    vector<vll> ans(n,vll(m));

    for(ll curr=nm; curr>0; curr--){
        if(m_x[curr]==0 && m_y[curr]==0){
            if(q.empty()){
                o1("No");
                return;
            }
            auto [i,j] = q.front();
            q.pop();
            ans[i][j] = curr;

            for(auto [ii,jj]: ok_to_fill[curr]){
                q.push({ii,jj});
            }
            continue;
        }

        if(m_x[curr]==0 || m_y[curr]==0){
            if(ok_to_fill[curr].empty()){
                o1("No");
                return;
            }

            auto [i,j] = ok_to_fill[curr].back();
            ok_to_fill[curr].pop_back();
            ans[i][j] = curr;

            for(auto [ii,jj]: ok_to_fill[curr]){
                q.push({ii,jj});
            }
            continue;
        }
        
        ans[m_x[curr]-1][m_y[curr]-1] = curr;
        for(auto [ii,jj]: ok_to_fill[curr]){
            if(ii!=m_x[curr]-1 || jj!=m_y[curr]-1) q.push({ii,jj});
        }        

    }  
    o1("Yes");
    for(ll i = 0; i < n; i++) {
        for(ll j=0; j<m; j++){
            cout << ans[i][j] << ' ' ;
        }
        cout << '\n';
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