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
    ll n;
    cin >> n;
    
    vll cnt(n+1);
    ll done = 0;
    stack<ll> stk;
    ll ask = 1;
    vector<vll> a2b(n+1, vll(n+1));
    ll m=0;
    while(done<n){
        cout << "? " << ask << '\n' << flush;            
        ll q1;
        cin >> q1;
        if(q1!=1) {
            cout << "q1 kyu 1 nhi h\n";
            return;
        }
        ll stNode;
        cin >> stNode;
        if(cnt[stNode]!=0){
            ask += cnt[stNode];
            continue;
        }
        cnt[stNode]++;
        stk.push(stNode);
        ask++;
        done++;

        while(!stk.empty()){            
            cout << "? " << ask << '\n' << flush;            
            ll q;
            cin >> q;
            if(q==0) break;
            vll path(q);
            iArray(path,q);
            if(stk.size()<q && path[stk.size()-1]==stk.top()){
                if(q!=stk.size()+1){
                    cout << "q stk.size()+1 kyu nhi h, first cond\n";
                    return;
                }                
                ll n_node = path[q-1];
                if(cnt[n_node]==0){
                    cnt[n_node]++;
                    a2b[stk.top()][n_node] = 1;
                    m++;
                    stk.push(n_node);
                    ask++;
                    done++;
                    
                }
                else{                    
                    ask += cnt[n_node];
                    cnt[stk.top()] += cnt[n_node];
                    a2b[stk.top()][n_node] = 1;
                    m++;
                    
                }
            }
            else{
                while(!stk.empty() && (stk.size()>=q || path[stk.size()-1]!=stk.top())){
                    ll x = stk.top();
                    stk.pop();
                    if(!stk.empty()) cnt[stk.top()] += cnt[x];
                }
                if(!stk.empty()){
                    if(q!=stk.size()+1){
                        cout << "q stk.size()+1 kyu nhi h\n";
                        return;
                    }
                    ll n_node = path[q-1];
                    if(cnt[n_node]==0){
                        cnt[n_node]++;
                        a2b[stk.top()][n_node] = 1;
                        m++;
                        stk.push(n_node);
                        ask++;
                        done++;
                        
                    }
                    else{                        
                        ask += cnt[n_node];
                        a2b[stk.top()][n_node] = 1;
                        cnt[stk.top()] += cnt[n_node];
                        m++;
                        
                    }                    
                }
                else{
                    if(q!=1){
                        cout << "q 1 kyu nhi h last cond\n";
                        return;
                    }
                    ll n_node = path[0];
                    if(cnt[n_node]==0){
                        cnt[n_node]++;                                                
                        stk.push(n_node);
                        ask++;
                        done++;
                        
                    }
                    else{                        
                        ask += cnt[n_node];
                        
                    } 
                }
                
            }
        }
    }
   
    cout << "! " << m << endl;
    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=n; j++){
            if(a2b[i][j]) cout << i << ' ' << j << endl;
        }
    }
    cout.flush();
    

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