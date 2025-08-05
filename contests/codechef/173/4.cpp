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
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    vector<ll> v(n+1);
    for(ll i = 0; i < n; i++) {
        v[p[i]] = i;
    }
    if(v[1]!=0 && v[1]!=n-1){
        o1("NO");
        return;
    }
    if(n==1){
        o1("YES");
        return;
    }
    if(v[2]!=0 && v[2]!=n-1){
        o1("NO");
        return;
    }
    set<ll> s;
    priority_queue<ll> pq;
    pq.push((n-1)/2);
    s.insert(0);
    s.insert(n-1);
    for(ll i = 3; i <= n; i++) {
        auto just_larger = s.upper_bound(v[i]); 
        auto just_smaller = (just_larger == s.begin()) ? s.end() : std::prev(just_larger);
        ll dist = LLONG_MAX;
        if (just_larger != s.end()) dist = min(dist, *just_larger - v[i]);
        if (just_smaller != s.end()) dist = min(dist, v[i] - *just_smaller);
        if(pq.top()==dist){
            pq.pop();
            s.insert(v[i]);
            pq.push((*just_larger - v[i])/2);
            pq.push((v[i]-*just_smaller)/2);
        }
        else{
            if(pq.top()<dist) cout << "haggu algo\n";
            else{
                o1("NO");
                return;
            }
        }
    }
    o1("YES");

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