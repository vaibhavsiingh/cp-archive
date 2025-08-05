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

const ll MOD = 1000000007;
const ll INF = 1e18;

void sol(){
    ll x,y,z,k;
    vll arrayy(3);
    cin >> arrayy[0] >> arrayy[1] >> arrayy[2] >> k;
    sort(all(arrayy));
    x = arrayy[0];
    y = arrayy[1];
    z = arrayy[2];
    k+=3;
    ll best = k/3;
    ll a,b,c;
    
    if(k%3==0){
        if(x>=best){
            a = best;
            b = best;
            c = best;
        }
        else{
            a = x;
            ll rem = k-a;
            best = rem/2;
            if(y>=best){
                b = best;
                if(rem-b<=z){
                    c=rem-b;
                }
                else c = best;
            }
            else{
                b = y;
                c = min(z,rem-y);
            }
        }
    }
    else if(k%3==1){
        if(x>=best){
            a = best;
            b = best;
            if(best+1<=z){
                c = best+1;
            }
            else c  = best;
        }
        else{
            a = x;
            ll rem = k-a;
            best = rem/2;
            if(y>=best){
                b = best;
                if(rem-b<=z){
                    c=rem-b;
                }
                else c = best;
            }
            else{
                b = y;
                c = min(z,rem-y);
            }
        }
    }
    else if(k%3==2){
        if(x>=best){
            a = best;
            if(best+1<=y){
                b = best+1;
                c = best+1;
            }
            else{
                b = best;
                if(best+2<=z){
                    c = best+2;
                }
                else if(best+1<=z){
                    c = best+1;
                }
                else c =best;
            }
        }
        else{
            a = x;
            ll rem = k-a;
            best = rem/2;
            if(y>=best){
                b = best;
                if(rem-b<=z){
                    c=rem-b;
                }
                else c = best;
            }
            else{
                b = y;
                c = min(z,rem-y);
            }
        }
    }
    o1(a*b*c);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sol();
}