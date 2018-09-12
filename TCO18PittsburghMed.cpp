#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Avoid9 {
	public:
		int dp[2][1<<9][1<<9];
		int n;
		int pre[1<<9][9];
		int maxSizeOf9Free(vector<int> A) {
			n = A.size();
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < (1<<9); ++i) {
				for (int j = 0; j < 9; ++j) {
					int ni = 0;
					for (int k = 0; k < 9; ++k) {
						if ((1<<k) & i) {
							int r = (k + j) % 9;
							ni |= (1<<r);
						}
					}
					pre[i][j] = ni;
				}
			}
			int now = 0;
			memset(dp, -1, sizeof(dp));
			dp[now][0][0] = 0;
			for (int i = 0; i < n; ++i) {
				int r = A[i] % 9;
				now = (i & 1);
				memset(dp[now ^ 1], -1, sizeof(dp[now ^ 1]));
				for (int j = 0; j < (1<<9); ++j) {
					for (int k = 0; k < (1<<9); ++k) {
						if (dp[now][j][k] < 0) continue;
						dp[now ^ 1][j][k] = max(dp[now ^ 1][j][k], dp[now][j][k]);
						int x = (9 - r) % 9;
					//	if (dp[now][j][k] == 3) cout<<i<<" "<<j<<" "<<k<<" "<<r<<" "<<x<<endl;
						if ((1<<x) & k) continue;
						dp[now ^ 1][j | (1<<r)][pre[j][r] | k] = max(dp[now ^ 1][j | (1<<r)][pre[j][r] | k], dp[now][j][k] + 1);
					}
				}
		//		for (int j = 0; j < (1<<9); ++j) {
			//		for (int k = 0; k < (1<<9); ++k) {
			//			if (dp[now ^ 1][j][k] >= 0) cout<<i<<" "<<j<<" "<<k<<" "<<dp[now ^ 1][j][k]<<endl;
			//		}
			//	}
			}
			now = (n & 1);
			int ans = 0;
			for (int i = 0; i < (1<<9); ++i) {
				for (int j = 0; j < (1<<9); ++j) {
					ans = max(ans, dp[now][i][j]);
				}
			}
			return (ans >= 3 ? ans : -1);
		}
};
