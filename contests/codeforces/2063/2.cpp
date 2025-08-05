#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll t;
    cin >> t;
    while (t--) {
        ll n, l, r;
        cin >> n >> l >> r;
        vector<ll> arr(n);
 
 
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
 
        ll rangeLength = r - l + 1;
 
 
        r = min(r, n);
 
        l = max(l, 1LL);
        ll start = l - 1;
 
 
        rangeLength = min(rangeLength, r);
        rangeLength = min(rangeLength, n - start);
 
        vector<ll> leftPart, rightPart;
 
 
        for (ll i = 0; i < r; i++) {
            leftPart.push_back(arr[i]);
        }
 
 
        for (ll i = start; i < n; i++) {
            rightPart.push_back(arr[i]);
        }
 
        sort(leftPart.begin(), leftPart.end());
        sort(rightPart.begin(), rightPart.end());
 
 
        ll leftSum = 0, rightSum = 0;
        for (ll i = 0; i < rangeLength; i++) {
            if (i < leftPart.size()) {
                leftSum += leftPart[i];
            }
            if (i < rightPart.size()) {
                rightSum += rightPart[i];
            }
        }
 
 
        cout << min(leftSum, rightSum) << "\n";
    }
 
    return 0;
}