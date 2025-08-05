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
        ll n,k;
        cin >> n >> k;
        vector<vll> v;
        ll count = 0;
        ll root = sqrt(n);
        vll temp;
        for(int i=1; i<=n; i++){
            if(count > root){
                count=0;
                v.push_back(temp);
            // oArray(temp, temp.size());
                temp.clear();
            }
            temp.push_back(i);
            count++;
        }
        if(temp.size()>0) v.push_back(temp);
        
    
        ll row =0, col = 0;
        for(int i=0; i<n; i++){
            ll pos = k%(n-i);
            

            if(pos+col < v[row].size()){
                //cout << "1st" << endl;
                col += pos;
                cout << (v[row][col]) << ' ';
                v[row].erase(v[row].begin() + col);
                if (v[row].empty()) {
                    v.erase(v.begin() + row);
                    col = 0;
                } else if (col == v[row].size()) {
                    col = 0;
                    row++;
                    if(row>=v.size()) row = 0;
                }
            }
            else{
                //cout << "2nd" << endl;
                pos -= (int)v[row].size()-col;
                col = 0;
                row++;
                // cout << endl << "pos-(int)v[row].size() " <<pos-(int)v[row].size() << endl;
                while(pos-(int)v[row].size()>=0){
                    pos -= (int)v[row].size();
                    row++;
                    if(row>=v.size()) row = 0;
                }
                // cout << endl << "row: " <<row << endl;
                col = pos;
                cout << (v[row][col]) << ' ';
                v[row].erase(v[row].begin() + col);
                if (v[row].empty()) {
                    v.erase(v.begin() + row);
                    col = 0;
                } else if (col == v[row].size()) {
                    col = 0;
                    row++;
                    if(row>=v.size()) row = 0;
                }

            }
            
        }  
        cout << '\n' ;

    }

    int main(){
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        sol();
    }

