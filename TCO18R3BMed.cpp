#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
float dp[1<<20][21][2];
class TestProctoring {
	public:
		int n;
		vector<double> pr;
		double dfs(int sta, int cur, int bit) {
			if (sta == 0 && cur == 0) return 0.0;
			if (dp[sta][cur][bit] >= 0.0) return dp[sta][cur][bit];
			if (cur == n) {
				if (!bit) return 0.0;
				return dp[sta][cur][bit] = dfs(sta, 0, 0) + 1.0;
			}
			double res = 0.0;
			if ((1<<cur) & sta) {
				res = dfs(sta ^ (1<<cur), cur + 1, 1) * pr[cur] + dfs(sta, cur + 1, bit) * (1.0 - pr[cur]);
			} else {
				res = dfs(sta, cur + 1, bit);
			}
			if (cur == 0) {
				double npr = 1.0;
				for (int i = 0; i < n; ++i) {
					if ((1<<i) & sta) {
						npr *= (1.0 - pr[i]);
					}
				}
				res = (res + npr) / (1.0 - npr);
			}
			return dp[sta][cur][bit] = res;
		}
		double expectedTime(vector<int> p, vector<int> q) {
			n = p.size();
			pr.clear();
			for (int i = 0; i < n; ++i) {
				pr.push_back((double)p[i] / (double)q[i]);
			}
			for (int i = 0; i < (1<<n); ++i) {
				for (int j = 0; j <= n; ++j) {
					for (int b = 0; b < 2; ++b) {
						dp[i][j][b] = -1;
					}
				}
			}
			return dfs((1<<n) - 1, 0, 0);
		}
};
