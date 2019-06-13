#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 500010
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[N];
class HomeAwayLeague {
	public:
		int matches(int x) {
			memset(dp, 0LL, sizeof(dp));
			dp[2] = 1LL;
			for (int i = 3; i <= x/ 2; ++i) {
				dp[i] = (dp[i-1]+dp[i-2]) % mod;
				dp[i] = dp[i] * (ll)(i-1) % mod;
			}
			ll ans = dp[x / 2];
			for (int i = x; i > x / 2; --i) {
				ans = ans * (ll)i % mod;
			}
			return ans;
		}
};
