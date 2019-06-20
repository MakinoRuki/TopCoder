#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
double dp[102][102];
class TorusSailing {
public:
	double expectedTime(int n, int m, int gx, int gy) {
		memset(dp, 0.0, sizeof(dp));
		for (int it = 0; it < 10000; ++it) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (i == 0 && j == 0) continue;
					dp[i][j] = (dp[(i-1+n)%n][j] + dp[i][(j-1+m)%m]) / 2.0 + 1.0;
				}
			}
		}
		return dp[gx][gy];
	}
};
