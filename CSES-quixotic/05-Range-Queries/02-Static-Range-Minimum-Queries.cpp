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
vll a;
const int INF = 1e10;


struct node{
    int val;
    node* child1;
    node* child2;
};

void recurse(ll i, ll j, node* nd){
    if(j-1==i){
        nd->val = min(a[i],a[j]);
    }
    else{
        recurse(i,i+(j-i)/2, nd->child1);
        recurse(i+(j-i)/2+1,j, nd->child2);
        nd->val = min(nd->child1->val, nd->child2->val);
    }
}

void sol(){
    ll n,q;
    i2(n,q);
    a.resize(n);
    iArray(a,n);
    ll bada_size = (1<<((int)log2(n)+1));
    for(int i=n; i<bada_size; i++){
        a.pb(INF);
    }
    node* baap = (node*)malloc(sizeof(node));
    recurse(0,bada_size-1,baap);
    
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}