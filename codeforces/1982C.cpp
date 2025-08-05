#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;

void sol() {
    ll n, l, r;
    cin >> n >> l >> r;
    vll v(n), sum(n);
    for(ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    sum[0] = v[0];
    for(ll i = 1; i < n; i++) {
        sum[i]=sum[i-1]+v[i];
    }

    ll ptr1=0,ptr2=0,ans=0;
    while(ptr1<n && ptr2<n){
        ll sm = sum[ptr2]-sum[ptr1]+v[ptr1]; 
        if(sm>=l && sm <= r){
            ++ans;
            ++ptr2;
            ptr1=ptr2;
        }
        else if(sm>r){
            if(ptr1<ptr2) ++ptr1;
            else{
                ++ptr2;
                ptr1=ptr2;
                continue;
            }
        }
        else{
            ++ptr2;
        }
    }
    cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++) {
        sol();
    }
}
