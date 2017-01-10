#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1400
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class PairsOfStrings {
public:
    vector<int> primes;
    ll dp[N];
    ll getPow (int a, int b) {
        ll res = 1LL;
        ll mul = (ll)a;
        while (b) {
            if (b & 1) {
                res = res * mul % mod;
            }
            mul = mul * mul % mod;
            b /= 2;
        }
        return res;
    }
    int getNumber (int n, int k) {
        primes.clear();
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                primes.push_back(i);
                if (i != n / i) {
                    primes.push_back(n / i);
                }
            }
        }
        sort(primes.begin(), primes.end());
        memset(dp, 0LL, sizeof(dp));
        dp[0] = k % mod;
        ll ans = dp[0];
        for (int i = 1; i < primes.size(); ++i) {
            dp[i] = getPow(k, primes[i]);
            for (int j = 0; j < i; ++j) {
                if (primes[i] % primes[j] == 0) {
                    dp[i] = (dp[i] - dp[j] + mod) % mod;
                }
            }
            ans = (ans + dp[i] * (ll)primes[i] % mod) % mod;
        }
        return (int)ans;
    }
};
