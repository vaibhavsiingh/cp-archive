#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;

#define oArray(a, n) for (ll i = 0; i < n; i++) cout << a[i] << ' '; cout << endl;

const ll MOD = 1e9 + 7;

// Optimized Sieve (O(n log log n))
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void sol() {
    ll n;
    cin >> n;
    ll num_primes = (n / 3) - 1;

    vector<bool> primes = sieve(n);
    vll perm(n, -1);
    vector<bool> used(n + 1, false);  

    ll curr_sum = 0;
    ll primes_found = 0;
    
    deque<ll> available;
    for (ll i = 1; i <= n; i++) available.push_back(i);  // Maintain order

    for (ll i = 1; i <= n && primes_found < num_primes; i++) {
        for (auto it = available.begin(); it != available.end(); it++) {
            ll cand = *it;
            if (primes[(cand + curr_sum + i - 1) / i]) {
                perm[i - 1] = cand;
                curr_sum += cand;
                used[cand] = true;
                available.erase(it);  // O(1) removal from deque
                primes_found++;
                break;
            }
        }
    }

    // Fill remaining positions efficiently
    auto it = available.begin();
    for (ll i = 0; i < n; i++) {
        if (perm[i] == -1) {
            perm[i] = *it;
            it++;
        }
    }

    oArray(perm, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        sol();
    }
}
