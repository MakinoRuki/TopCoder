#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class EraseToGCD {
	public:
		ll dp[502][1002];
		int n;
		int countWays(vector <int> S, int goal) {
			memset(dp, 0LL, sizeof(dp));
			dp[0][0] = 1LL;
			n = S.size();
			int mx = 0;
			for (int i = 0; i < S.size(); ++i) {
				mx = max(mx, S[i]);
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= mx; ++j) {
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
					int nj = __gcd(j, S[i]);
					dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j]) % mod;
				}
			}
			ll ans = dp[n][goal];
			return (int) ans;
		}
};
