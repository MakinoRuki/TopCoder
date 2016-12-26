#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
#define inf 1000000000
using namespace std;
class BiconnectedDiv1 {
	public:
		int n;
		int dp[N][3];
		int minimize (vector<int> w1, vector<int> w2) {
			n = w1.size() + 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < 3; ++j) {
					dp[i][j] = inf;
				}
			}
			dp[0][0] = w1[0] + w2[0];
			for (int i = 0; i < n - 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (dp[i][j] >= inf) continue;
					if (j == 0) {
						if (i + 1 != n - 3) {
							dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + w1[i + 1]);
						}
						if (i + 1 != n - 2) {
							dp[i + 1][2] = min(dp[i + 1][2], dp[i][j] + w2[i + 1]);
						}
					} else if (j == 1) {
						if (i + 1 != n - 2) {
							dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + w1[i + 1] + w2[i + 1]);
						}
					} else {
						if (i + 1 != n - 3) {
							dp[i + 1][1] = min(dp[i + 1][1], dp[i][j] + w1[i + 1]);
						}
						if (i + 1 != n - 2) {
							dp[i + 1][2] = min(dp[i + 1][2], dp[i][j] + w2[i + 1]);
						}
					}
				}
			}
			return dp[n - 2][1];
		}
};
