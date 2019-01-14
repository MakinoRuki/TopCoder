#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2505
using namespace std;
class ExpectedSum {
	public:
		double dp[2][N][N];
		int n;
		double solve(vector<int> seq, vector<int> mprob) {
			n = seq.size();
			dp[0][0][0] = 1.0;
			for (int i = 0; i < n; ++i) {
				int now = (i & 1);
				for (int j = 0; j <= i * 50; ++j) {
					for (int k = 0; k <= i * 50; ++k) {
						dp[now ^ 1][j][k] = 0.0;
					}
				}
				for (int j = 0; j <= i * 50; ++j) {
					for (int k = 0; k <= i * 50; ++k) {
						double mpr = (double)mprob[i] / 100.0;
						dp[now ^ 1][j + seq[i]][max(k, j + seq[i])] += dp[now][j][k] * (1.0 - mpr);
						dp[now ^ 1][max(0, j - seq[i])][k] += dp[now][j][k] * mpr;
					}
				}
			}
			double ans = 0.0;
			for (int k = 0; k <= n * 50; ++k) {
				for (int j = 0; j <= n * 50; ++j) {
					ans += (double)k * dp[n & 1][j][k];
				}
			}
			return ans;
		}
};
