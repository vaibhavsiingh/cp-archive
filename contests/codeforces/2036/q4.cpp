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
    int n,m;
    i2(n,m);
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char x;
            cin >> x;
            mat[i][j] = x - '0';
        }
    }
    int count =0;
     int top = 0, l = 0, bottom = n - 1, r = m - 1;

    while (top <= bottom && l <= r) {    
    vector<int> ans;
    for (int i = l; i <= r; i++)
      ans.push_back(mat[top][i]);

    top++;

    
    for (int i = top; i <= bottom; i++)
      ans.push_back(mat[i][r]);

    r--;
    
    
    if (top <= bottom) {
      for (int i = r; i >= l; i--)
       ans.push_back(mat[bottom][i]);

      bottom--;
    }

    
    if (l <= r) {
      for (int i = bottom; i >= top; i--)
        ans.push_back(mat[i][l]);

      l++;
    }
    if(ans.size()>=4){
        ans.push_back(ans[0]);
        ans.push_back(ans[1]);
        ans.push_back(ans[2]);
    }
    // count the number of occurences of 1543 in the array
    for(int i=0; i<ans.size()-3; i++){
        if(ans[i]==1 && ans[i+1]==5 && ans[i+2]==4 && ans[i+3]==3){
            count++;
        }
    }
    } 
    o1(count);
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