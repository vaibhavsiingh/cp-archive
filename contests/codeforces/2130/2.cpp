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
    int n,s;
    cin >> n >> s;
    vector<int> c(3);
    int x;
    int sm=0;
    for(int i=0; i<n; i++){
        cin >> x;
        c[x]++;
        sm+=x;
    }
    s-=sm;
    if(s<0){
        for(int i=0; i<3; i++){
            while(c[i]){
                cout << i << ' ';
                c[i]--;
            }
        }
        cout << '\n';
        return;
    }


    if(c[1]==0 && c[2]==0){
        if(s==0){
            o1(-1);
            return;
        }
        else{
            for(int i=0; i<3; i++){
                while(c[i]){
                    cout << i << ' ';
                    c[i]--;
                }
            }
            cout << '\n';
            return;
        }
    }
    if(c[0]==0 && c[2]==0){
        if(s%2==0){
            o1(-1);
            return;
        }
        else{
            for(int i=0; i<3; i++){
                while(c[i]){
                    cout << i << ' ';
                    c[i]--;
                }
            }
            cout << '\n';
            return;
        }
    }
    if(c[0]==0 && c[1]==0){
        if(s%4==0){
            o1(-1);
            return;
        }
        else{
            for(int i=0; i<3; i++){
                while(c[i]){
                    cout << i << ' ';
                    c[i]--;
                }
            }
            cout << '\n';
            return;
        }
    }
    if(c[2]==0){
        
        o1(-1);
        return;
         
    }
    if(c[1]==0){
        if(s%2==0){
            o1(-1);
            return;
        }
        else{
            for(int i=0; i<3; i++){
                while(c[i]){
                    cout << i << ' ';
                    c[i]--;
                }
            }
            cout << '\n';
            return;
        }
    }
    if(c[0]==0){
        if(c[1]>1){
            if(s!=1){
                o1(-1);
            }
            else{
                for(int i=0; i<3; i++){
                    while(c[i]){
                        cout << i << ' ';
                        c[i]--;
                    }
                }
                cout << '\n';
                return;
            }
        }
        else{
            if(s==3 || s==4){
                for(int i=0; i<3; i++){
                    while(c[i]){
                        cout << i << ' ';
                        c[i]--;
                    }
                }
                cout << '\n';
                return;
            }
            else{
                cout << -1 << '\n';
            }
        }        
    }
    else{
        if(s!=1){
            o1(-1);
        }
        else{
            while(c[0]){
                cout << 0 << ' ';
                c[0]--;
            }
            while(c[2]){
                cout << 2 << ' ';
                c[2]--;
            }
            while(c[1]){
                cout << 1 << ' ';
                c[1]--;
            }
            cout << '\n';
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