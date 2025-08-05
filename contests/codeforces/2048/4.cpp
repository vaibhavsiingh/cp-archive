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
    vector<int> people;
    int kevin;
    cin >> kevin;
    for(int i=1; i<n; i++){
        int x;
        cin >> x;
        if(true){
            people.push_back(x);
        }
    }
    vector<int> ques(m);
    for(int i=0; i<m; i++){
        cin >> ques[i];
    }
    sort(people.begin(),people.end());
    sort(ques.begin(),ques.end());

    vector<int> c;
    int ptr_people = 0, ptr_ques = 0;
    while(ptr_ques < m && ques[ptr_ques]<=kevin ){
        c.push_back(0);
        ptr_ques++;
    }
    while(ptr_people < n-1 && ptr_ques < m){
        int count = 0;
        while(ptr_people < n-1 && people[ptr_people]>=ques[ptr_ques]){
            count++;
            ptr_people++;
        }
        c[ptr_ques] = count;
        ptr_ques++;
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
}