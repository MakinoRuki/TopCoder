#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class DerangementsStrikeBack {
	public:
		ll dp[N];
		int count(int n, int m) {
			memset(dp, 0, sizeof(dp));
			dp[0] = 1LL;
			ll ans = 0LL;
			dp[1] = dp[0] * (ll)n % mod;
			ans = dp[1];
			for (int i = 2; i <= m; ++i) {
				dp[i] = (dp[i - 1] * (ll)(n + i - 1) % mod + dp[i - 2] * (ll)(i - 1) % mod) % mod;
				ans = ans ^ dp[i];
			}
			return ans;
		}
};
