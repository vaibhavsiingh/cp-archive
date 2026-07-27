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
    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vll a(n);
    iArray(a, n);

    if(n == 1){
        if(s[0] == '0' || a[0] == k){
            o1("Yes");
            o1(k);
            return;
        }
        else{
            o1("No");
            return;
        }
    }

    vector<ll> max_sum_so_far(n);
    vector<ll> calculate(n);

    auto calc = [&](ll l, ll r){
        ll mx_so_far = a[l];
        ll mx = a[l];
        ll sm = a[l];
        ll mx_sm = a[l];

        max_sum_so_far[l] = mx_so_far;

        for(ll i = l + 1; i <= r; i++) {
            mx_so_far = max(a[i], mx_so_far + a[i]);
            max_sum_so_far[i] = mx_so_far;

            mx = max(mx_so_far, mx);

            sm += a[i];
            mx_sm = max(sm, mx_sm);
        }

        calculate[l] = mx_sm;

        return mx;
    };

    ll mx_count = 0;
    ll start0 = -1;

    for(ll i = 0; i < n; ){

        ll count = 0;
        ll temp_start = i;

        while(i < n && s[i] == '0'){
            i++;
            count++;
        }

        if(mx_count < count){
            start0 = temp_start;
        }

        mx_count = max(count, mx_count);

        if(i >= n) break;

        ll start = i;

        while(i < n && s[i] == '1'){
            i++;
        }

        ll subarrysum = calc(start, i - 1);

        if(subarrysum > k){
            o1("No");
            return;
        }
    }

    ll boundary = -1e13;

    if(n >= 2 && s[0] == '0' && s[1] == '0'){
        cout << "Yes" << endl;
        cout << k << " " << boundary << ' ';

        for(ll i = 2; i < n; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        o1("");
        return;
    }

    if(n >= 2 && s[n-2] == '0' && s[n-1] == '0'){
        cout << "Yes" << endl;

        for(ll i = 0; i < n - 2; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        cout << boundary << " " << k << '\n';
        return;
    }

    if(mx_count == 0){
        if(calc(0, n - 1) == k){
            o1("Yes");
            oArray(a, n);
        }
        else{
            o1("No");
        }

        return;
    }

    if(mx_count >= 3){
        cout << "Yes" << endl;

        for(ll i = 0; i < start0; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        cout << boundary << ' ' << k << ' ' << boundary << endl;

        for(ll i = start0 + 3; i < n; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        o1("");
        return;
    }

    if(mx_count == 2){
        cout << "Yes" << endl;

        for(ll i = 0; i < start0; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        ll out;

        if(start0 > 0 && max_sum_so_far[start0 - 1] >= 0)
            out = k - max_sum_so_far[start0 - 1];
        else
            out = k;

        cout << out << ' ' << boundary << ' ';

        for(ll i = start0 + 2; i < n; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        o1("");
        return;
    }

    if(s[0] == '0'){
        cout << "Yes" << endl;

        ll out;

        if(calculate[1] > 0) out = k - calculate[1];
        else out = k;

        cout << out << ' ';

        for(ll i = 1; i < n; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        o1("");
        return;
    }

    if(s[n - 1] == '0'){
        cout << "Yes" << endl;

        for(ll i = 0; i < n - 1; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        ll out;

        if(max_sum_so_far[n - 2] < 0) out = k;
        else out = k - max_sum_so_far[n - 2];

        cout << out << '\n';
        return;
    }

    if(mx_count == 1){
        cout << "Yes" << endl;

        for(ll i = 0; i < start0; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        ll left = (start0 > 0 ? max(max_sum_so_far[start0 - 1], (ll)0) : 0);
        ll right = max(calculate[start0 + 1], (ll)0);

        cout << k - left - right << ' ';

        for(ll i = start0 + 1; i < n; i++){
            if(s[i] == '0') cout << boundary << ' ';
            else cout << a[i] << ' ';
        }

        o1("");
        return;
    }

    o1("No");
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    for(ll i = 0; i < t; i++) {
        sol();
    }

    return 0;
}


