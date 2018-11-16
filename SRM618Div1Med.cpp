#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 5002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class LongWordsDiv1 {
public:
	ll dp[N];
	int count(int n) {
		memset(dp, 0LL, sizeof(dp));
		dp[0] = 1LL;
		for (int i = 1; i <= n; ++i) {
			dp[i] = dp[i - 1];
			for (int j = 1; j <= i - 2; ++j) {
				dp[i] = (dp[j] * dp[i - 1 - j] % mod) % mod;
			}
		}
		ll ans = dp[n];
		for (int i = 1; i <= n; ++i) {
			ans = ans * (ll)i % mod;
		}
		return (int)ans;
	}
};
