#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2800
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll comb[N][N];
ll dp[N];
class OrderedProduct {
	public:
		int n;
		int count (vector<int> a) {
			n = a.size();
			memset(comb, 0LL, sizeof(comb));
			int tot = 0;
			for (int i = 0; i < n; ++i) {
				tot += a[i];
			}
			for (int i = 0; i <= tot + 52; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			memset(dp, 0LL, sizeof(dp));
			ll ans = 0LL;
			for (int i = 1; i <= tot; ++i) {
				dp[i] = 1LL;
				for (int j = 0; j < n; ++j) {
					dp[i] = dp[i] * comb[i + a[j] - 1][i - 1] % mod;
				}
				for (int j = 1; j < i; ++j) {
					dp[i] = (dp[i] - dp[j] * comb[i][j] % mod + mod) % mod;
				}
				ans = (ans + dp[i]) % mod;
			}
			return ans;
		}
};
