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

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    vll csize;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        csize.resize(size,1);
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                csize[rootX] += csize[rootY];
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                csize[rootY] += csize[rootX];
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
                csize[rootX] += csize[rootY];
            }
        }
    }

    ll sizeOf(int n){
        return csize[find(n)];
    }
};


void sol(){
    ll n,m;
    i2(n,m);
    UnionFind s(n+1);
    ll ncomp = n;
    ll mxSize=1;
    while(m--){
        
        ll x,y;
        i2(x,y);
        if(s.find(x)==s.find(y)){
            o2(ncomp,mxSize);
            continue;
        }
        s.unite(x,y);
        mxSize = max(mxSize, s.sizeOf(x));
        ncomp--;
        o2(ncomp, mxSize);
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}