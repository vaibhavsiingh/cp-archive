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

ll maxEarningsWithLimitedNegativeReviews(int n, int k, vector<int>& a, vector<int>& b) {
    // Store events as (price, type, customer_id)
    // type: 1 = switch to negative review, 2 = stop buying
    vector<tuple<int, int, int>> events;
    events.reserve(2 * n);
    
    // Create events for each customer
    for(int i = 0; i < n; i++) {
        events.emplace_back(a[i], 1, i);
        events.emplace_back(b[i], 2, i);
    }
    
    // Sort events:
    // 1. By price ascending
    // 2. For same price, "stop buying" comes before "switch to negative"
    // 3. For same type, by customer_id
    sort(events.begin(), events.end());
    
    ll maxEarnings = 0;
    int customers = n;  // Start assuming price = 0
    int negReviews = 0;
    int prevPrice = 0;
    
    // Process each distinct price point
    int i = 0;
    while(i < events.size()) {
        int currentPrice = get<0>(events[i]);
        
        // If current state valid, calculate earnings
        if(negReviews <= k) {
            ll earnings = (ll)customers * currentPrice;
            maxEarnings = max(maxEarnings, earnings);
        }
        
        // Process all events at current price
        while(i < events.size() && get<0>(events[i]) == currentPrice) {
            int type = get<1>(events[i]);
            if(type == 2) {  // Stop buying
                customers--;
                negReviews--;
            } else {  // Switch to negative
                negReviews++;
            }
            i++;
        }
    }
    
    return maxEarnings;
}

void sol(){
        int n, k;
    cin >> n >> k;
    
    vector<int> a(n), b(n);
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    ll result = maxEarningsWithLimitedNegativeReviews(n, k, a, b);
    cout << result << "\n";

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