#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 101
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class XYZCoder {
	public:
		ll dp[N][N];
		ll comb[N][N];
		int countWays (int room, int size) {
			memset(dp, 0LL, sizeof(dp));
			dp[0][0] = 1LL;
			ll facn = 1LL;
			for (int i = 1; i <= room; ++i) {
				facn = facn * (ll)i % mod;
			}
			memset(comb, 0LL, sizeof(comb));
			for (int i = 0; i <= size; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			for (int i = 1; i < room; ++i) {
				for (int j = 1; j < room; ++j) {
					for (int k = 0; k <= max(0, j - i + 1); ++k) {
						dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * comb[size][k] % mod) % mod;
					}
				}
			}
			return dp[room - 1][room - 1] * facn % mod;
		}
};
