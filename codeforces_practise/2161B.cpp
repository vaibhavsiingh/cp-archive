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
    vector<string> grid(n);
    ll nb = 0;
    ll posx = -1, posy=-1; 
    for(ll i = 0; i < n; i++) {        
        cin >> grid[i];
        for(auto x: grid[i]) nb += (x=='#');        
    }
    for(posx=0; posx<n; posx++){
        for(posy=0; posy<n; posy++){
            if(grid[posx][posy]=='#') goto label;
        }
    }
    label:
    if(posx==n){
        o1("YES");
        return;
    }
    ll cnt = 1;
    if(nb<=4){
        if(posx<n && posy+1<n && grid[posx][posy+1]=='#') cnt++;
        if(posx+1<n && posy+1<n && grid[posx+1][posy+1]=='#') cnt++;
        if(posx+1<n && posy<n && grid[posx+1][posy]=='#') cnt++;
        if(cnt==nb){
            o1("YES");
            return;
        }
    }
    
    cnt = 1;
    ll i=posx, j = posy-1;
    ll toss = 0;
    while(i<n && j>=0){        
        if(grid[i][j]=='#') cnt++;
        if(toss==0)i++;
        else j--;
        toss = (toss+1)%2; 
    }
    if(cnt==nb){
        o1("YES");
        return;
    }

    cnt = 1;
    i=posx, j = posy+1;
    toss = 0;
    while(i<n && j<n){        
        if(grid[i][j]=='#') cnt++;
        if(toss==0)i++;
        else j++;
        toss = (toss+1)%2; 
    }
    if(cnt==nb){
        o1("YES");
        return;
    }

    cnt = 1;
    i=posx+1, j = posy;
    toss = 0;
    while(i<n && j<n){        
        if(grid[i][j]=='#') cnt++;
        if(toss==0)j++;
        else i++;
        toss = (toss+1)%2; 
    }
    if(cnt==nb){
        o1("YES");
        return;
    }

    cnt = 1;
    if(posx<n && posy+1<n && grid[posx][posy+1]=='#') cnt++;
    i=posx+1, j = posy;
    toss = 0;
    while(i<n && j>=0){        
        if(grid[i][j]=='#') cnt++;
        if(toss==0)j--;
        else i++;
        toss = (toss+1)%2; 
    }
    if(cnt==nb){
        o1("YES");
        return;
    }
    o1("NO");
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