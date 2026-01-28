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
    ll n,m,l;
    double x,y;
    cin >> n >> m >> l >> x >> y;
    vector<vector<double>> buses(n, vector<double>(3));
    
    for(ll i = 0; i < n; i++) {
        cin >> buses[i][0] >>  buses[i][2];
        buses[i][1] = buses[i][0]+ (1- y/x)*(buses[i][2]-buses[i][0]);
    }
    sort(buses.begin(),buses.end());

    map<pair<double,double>,double> ans;
    map<double,double> ans2;
    
    ll idx = 0;
    double p0 = buses[idx][0], p1 = buses[idx][1];
    if(p0!=0) ans[{0,p0}] = -1, ans2[0] = -1;
    ans[{p0,p1}] = (buses[idx][2]-p0)/x + (l-buses[idx][2])/y;
    ans2[p0] = (buses[idx][2]-p0)/x + (l-buses[idx][2])/y;

    priority_queue<vector<double>> pq;
    pq.push({buses[idx][2],-p0,p1});


    while(idx<n-1){
        double curr = min(p1,buses[idx+1][0]);
        if(p1+1e-5<buses[idx+1][0]){
            if(!pq.empty()) pq.pop();
            while(!pq.empty() && pq.top()[2]+1e-5<curr) pq.pop();
            if(!pq.empty()){
                vector<double> temp = pq.top();
         //       cout << p1 << ' ' << temp[2] << endl;
                ans[{p1,temp[2]}] = (temp[0]+temp[1])/x + (l-temp[0])/y;
                ans2[p1] = (temp[0]+temp[1])/x + (l-temp[0])/y;
                p0 = -temp[1], p1 = temp[2];                
            }
            else{
                ans[{p1,INF}] = -1;     
                ans2[p1]      = -1;
                p0 = p1;
                p1 = INF;
            }
        }
        else{
            pq.push({buses[idx+1][2],-buses[idx+1][0],buses[idx+1][1]});
            p0 = curr;
            p1 = pq.top()[2];
         //   cout << p0 << ' ' << p1 << endl;
            ans[{p0,p1}] = (pq.top()[0]+pq.top()[1])/x+(l-pq.top()[0])/y;
            ans2[p0] = (pq.top()[0]+pq.top()[1])/x+(l-pq.top()[0])/y;
            idx++;
        }        
    }

    ans[{p1, INF}] =-1;

    while(m--) {
        ll s;
        cin >> s;
        auto itr = ans2.lower_bound(s);
        if(itr->first > s && itr!=ans2.begin()) itr--;
        cout << itr->first <<' ' << itr->second << endl;
        if(itr->first>=s && itr->second!=-1){
            o1(itr->second);
        }
        else{
            o1((l-s)/y);
        }
    }

    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}