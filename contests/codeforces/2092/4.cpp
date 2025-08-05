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

ll letter_to_insert(char a, char b){
    ll ans = 0;
    if(a=='L'){
        if(b=='I'){
            ans = 2;
        }
        else{
            ans = 1;
        }
    }
    if(a=='I'){
        if(b=='T'){
            ans = 0;
        }
        else{
            ans = 2;
        }
    }
    if(a=='T'){
        if(b=='I'){
            ans = 0;
        }
        else{
            ans = 1;
        }
    }
    return ans;
}

char idx2char(int x){
    if(x==0) return 'L';
    if(x==1) return 'I';
    if(x==2) return 'T';
}
void sol(){
    unordered_map<char, int> m;
    m['L'] = 0;
    m['I'] = 1;
    m['T'] = 2;

    ll n;
    cin >> n;
    string s;
    cin >> s;
   

    vll count(3);
    for(ll i=0; i<n; i++){
        count[m[s[i]]]++;
    }

    ll valid_k = -1;
    for(int k=0; k<2*n+1; k++){
        if((n+k)%3!=0) continue;
        ll target = (n+k)/3;
        if(count[0]<=target && count[1]<=target && count[2]<=target){
            valid_k = k;
            break;
        }
    }
    if(valid_k==-1){
        o1(-1);
        return;
    }

    ll target = (n+valid_k)/3;
    vll need(3);
    need[0] = target - count[0];
    need[1] = target - count[1];
    need[2] = target - count[2];

    vll ans;
    ll ans_c = 0;
    ll curr_len = n;
    while(need[0]>0 || need[1]>0 || need[2]>0){
        bool made_progress = false;
        ll i =0;
        while(i<s.length()-1 && ans_c < 2*n){
            if(s[i]!=s[i+1]){
                ll letter_insertion = letter_to_insert(s[i],s[i+1]);
                if(need[letter_insertion]>0){
                    ans.pb(i+1);
                    s.insert(s.begin() + i + 1, idx2char(letter_insertion));
                    need[letter_insertion]--;                    
                    ans_c++;
                    made_progress = true;
                    i = 0;
                    continue;
                }
            }
            i++;
        }
        if(!made_progress) break;
    }

    if(need[0]>0 || need[1]>0 || need[2] >0){
        o1(-1);
        return;
    }
    o1(ans_c);
    for(int i=0; i<ans_c; i++){
        o1(ans[i]);
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