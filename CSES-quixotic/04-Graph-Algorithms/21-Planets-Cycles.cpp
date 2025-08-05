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
#define all(x) x.begin(), x.end()
#define YN(possible) cout << ((possible) ? "Yes" : "No") << endl;

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll n;
    cin >> n;
    vll nxt(n+1);
    for(ll i=1; i<=n; i++) cin >> nxt[i];
    vll visited(n+1);
    vll ans(n+1,-1);
    for(ll i=1; i<=n; i++){
        if(!visited[i]){            
            ll p1=i,p2=i;
            ll count = 0;
            while(!visited[p1]){
                visited[p1] = 1;
                p1 = nxt[p1];
                count++;
            }
            if(ans[p1]!=-1){
                ll temp = ans[p1];
                p1 = i;
                while(count){
                    ans[p1] = temp+count;
                    --count;
                    p1 = nxt[p1];
                }
                continue;
            }
            p1 = i;
            p1 = nxt[p1];
            p2 = nxt[nxt[p2]];

            while(p1!=p2){
                p1 = nxt[p1];
                p2 = nxt[nxt[p2]];                              
            }
            p1 = i;            
            while(p1!=p2){
                p1 = nxt[p1];
                p2 = nxt[p2];
            }
            ll len_cycle = 1;
            p1 = nxt[p1];
            while(p1!=p2){
                p1 = nxt[p1];
                len_cycle++;
            }
            p1 = i;
            ll len_a = 0;
            while(p1!=p2){
                p1 = nxt[p1];
                len_a++;
            }
            p1 = i;
            while(p1!=p2){
                ans[p1] = len_a+len_cycle;
                
                len_a--;
                p1 = nxt[p1];
            }
            ans[p1] = len_cycle;
            
            p1 = nxt[p1];
            while(p1!=p2){
                
                ans[p1] = len_cycle;
                p1 = nxt[p1];
            }            

        }
    }
    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout <<"\n";

}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}