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

const ll MOD = 1000000007;

void sol(){
    string s1,s2;
	cin >> s1 >> s2;
	ll n1 = s1.length(), n2 = s2.length();
    ll p1=0,p2=0;
    while(p1 < n1 && p2 < n2){
        if(s1[p1]==s2[p2]){
            p1++;
            p2++;
        }
        else p1++;
    }
    if(p2<n2){
        o1(-1);
        return;
    }
    vll mark(n1);
    p2 = n2-1;
    for(int i=n1-1; p2>=0 && i>=0; i--){
        if(s1[i]==s2[p2]){
            p2--;
            mark[i]++;
        }
    }
    ll cost = 0;
    ll ele = 0;
    for(ll i = 0; i < n1; i++) {
        if(!mark[i]){
            cost += (i+1)-ele;
            ele++;
        }
    }
    o1(cost);
    
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