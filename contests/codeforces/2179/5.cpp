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
    ll n,a,b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vll p(n);
    iArray(p,n);

    ll a_win = 0, b_win = 0;
    ll a_cost = 0, b_cost = 0;
    ll mx_dis_a=0, mx_dis_b=0;
    for(ll i = 0; i < n; i++) {
        if(s[i]=='0'){
            a_win  = 1;
            a_cost += p[i];
            mx_dis_a += (p[i]-1)/2;
        }
        else{
            b_win = 1;
            b_cost += p[i];
            mx_dis_b += (p[i]-1)/2;
        }
    }

    if(a_win && b_win){
        if(a_cost<a && b_cost<b){
            o1("YES1");
            return;
        }        
        else if (a_cost>a && b_cost>b){
            o1("NO");
            return;
        }
        else{
            if(a>=a_cost){
                ll a_can_give = min(a-a_cost, mx_dis_b);
                b += a_can_give;
                b_cost -= a_can_give;
                if(b<b_cost){
                    o1("NO");
                    return;
                }
                
            }
            else{
                ll b_can_give = min(b-b_cost, mx_dis_a);
                
                a += b_can_give;
                a_cost -= b_can_give;
                if(a<a_cost){
                    o1("NO");
                    return;
                }
            }
            o1("YES2");
            return;
        }
    }
    if(a_win){
        if(a>=a_cost && a-a_cost >= b){
            o1("YES3");
            return;
        }
        else{
            ll b_can_give = min(b-b_cost, mx_dis_a);
            a += b_can_give;
            a_cost -= b_can_give;
            b -= b_can_give;
            o2(a-a_cost, b);
            if(a<a_cost || a-a_cost < b){
                o1("NO");
                return;
            
            }
            o1("YES4");
            return;
        }
    }
    if(b_win){
        if(b>=b_cost){
            o1("YES5");
            return;
        }
        else{
            ll a_can_give = min(a-a_cost, mx_dis_b);
            b += a_can_give;
            a_cost -= a_can_give;
            a -= a_can_give;
            if(b<b_cost || a>b-b_cost){
                o1("NO");
                return;
            
            }
            o1("YES6");
            return;
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
    return 0;
}