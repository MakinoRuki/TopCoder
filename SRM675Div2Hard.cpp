#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class TreeAndPathLength2 {
	public:
		bool dp[N][N][1002];
		string possible (int n, int s) {
			memset(dp, false, sizeof(dp));
			dp[1][1][0] = true;
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= i; ++j) {
					for (int k = 0; k <= s; ++k) {
						if (dp[i][j][k]) {
							for (int t = 1; t + i <= n; ++t) {
								int nk = k + t * (t - 1) / 2;
								if (i > 1) nk += t;
								if (nk <= s) {
									dp[i + t][j - 1 + t][nk] = true;
								}
							}
						}
					}
				}
			}
			for (int i = 1; i <= n; ++i) {
				if (dp[n][i][s]) return "Possible";
			}
			return "Impossible";
		}
};
