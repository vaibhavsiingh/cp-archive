#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void sol(){
    ll n;
    cin >> n;

    vll a(n);
    for(ll i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;

    for(ll cand = 1; cand * cand <= n; cand++){        

        vector<char> seen(n, 0);

        
        for(ll j = 0; j < n; j++){
            ll i = j - cand * a[j];
            if(i >= 0 && i < n && seen[i])
                ans++;
            if(a[j] == cand)
                seen[j] = 1;
        }

        fill(seen.begin(), seen.end(), 0);

        
        for(ll i = n - 1; i >= 0; i--){
            if(a[i] * a[i] > n){
                ll j = i + cand * a[i];
                if(j >= 0 && j < n && seen[j])
                    ans++;
            }
            if(a[i] == cand)
                seen[i] = 1;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--) sol();

    return 0;
}
