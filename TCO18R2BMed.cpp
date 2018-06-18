#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1024
#define inf 1000000000
using namespace std;
class LineColoring {
	public:
		int n;
		int dp[N][3];
		int minCost (vector<int> x) {
			n = x.size();
			int ans = inf;
			int maxv = 0;
			int max1 = 0;
			int max2 = 0;
			for (int i = 0; i < n; ++i) {
				if (i & 1) max1 = max(max1, x[i]);
				else max2 = max(max2, x[i]);  
			}
			maxv = max(max1, max2);
			ans = max1 + max2;
			for (int i = 0; i < n; ++i) {
				int minv = x[i];
				for (int j = 0; j <= n; ++j) {
					for (int k = 0; k < 3; ++k) {
						dp[j][k] = inf;
					}
				}
				dp[0][0] = 0;
				dp[0][1] = x[0];
				if (x[0] <= minv) dp[0][2] = x[0];
				for (int j = 1; j < n; ++j) {
					for (int k1 = 0; k1 < 3; ++k1) {
						for (int k2 = 0; k2 < 3; ++k2) {
							if (k1 == k2) continue;
							if (k2 == 0)
							dp[j][k2] = min(dp[j][k2], dp[j - 1][k1]);
							if (k2 == 1)
							dp[j][k2] = min(dp[j][k2], max(dp[j - 1][k1], x[j]));
							if (k2 == 2 && x[j] <= minv)
							dp[j][k2] = min(dp[j][k2], dp[j - 1][k1]);
						}
					}
				}
				for (int j = 0; j < 3; ++j) {
					ans = min(ans, dp[n - 1][j] + minv + maxv);
				}
			}
			return ans;
		}
};
