#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class ClassRankings {
	public:
		ll dp[2][52][52][1005];
		int countWays(vector<int> amt, vector<int> lo, vector<int> hi) {
			memset(dp, 0, sizeof(dp));
			dp[0][0][0][0] = 1;
			int maxv = max(max(hi[0], hi[1]), hi[2]);
			for (int i = 0; i <= amt[0]; ++i) {
				int now = i & 1;
				memset(dp[now^1], 0, sizeof(dp[now^1]));
				for (int j = 0; j <= amt[1]; ++j) {
					for (int k = 0; k <= amt[2]; ++k) {
						for (int t = 0; t <= maxv; ++t) {
							if (i + 1 <= amt[0]) {
								int s = max(t+1, lo[0]);
								if (s <= hi[0]) {
									dp[now^1][j][k][s] = (dp[now^1][j][k][s] + dp[now][j][k][t]) % mod;
								}
							}
							if (j + 1 <= amt[1]) {
								int s = max(t+1, lo[1]);
								if (s <= hi[1]) {
									dp[now][j+1][k][s] = (dp[now][j+1][k][s] + dp[now][j][k][t]) % mod;
								}
							}
							if (k + 1 <= amt[2]) {
								int s = max(t+1, lo[2]);
								if (s <= hi[2]) {
									dp[now][j][k+1][s] = (dp[now][j][k+1][s] + dp[now][j][k][t]) % mod;
								}
							}
						}
					}
				}
			}
			ll ans = 0LL;
			for (int t = 0; t <= maxv; ++t) {
				ans = (ans + dp[amt[0]&1][amt[1]][amt[2]][t]) % mod;
			}
			return ans;
		}
};
