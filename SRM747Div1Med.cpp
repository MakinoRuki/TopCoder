#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class TieForMax {
	public:
		double comb[N][N];
		double dp[N][N];
		double getProbability(int t, int p) {
			for (int i = 0; i <= max(t, p); ++i) {
				comb[i][0] = 1.0;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]);
				}
			}
			double ans = 0;
			for (int mx = 1; mx <= t; ++mx) {
				dp[0][0] = 1;
				for (int i = 1; i <= p; ++i) {
					for (int j = 0; j <= t; ++j) {
						dp[i][j] = 0;
						for (int k = 0; k <= min(j, mx - 1); ++k) {
							dp[i][j] += dp[i - 1][j - k] * comb[j][k];
						}
					}
				}
				ans += dp[p - 1][t - mx] * comb[t][mx] * p;
			}
			for (int i = 1; i <= t; ++i) {
				ans /= (double)p;
			}
			ans = 1.0 - ans;
			return ans;
		}
};
