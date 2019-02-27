#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 52
#define inf 1000000000
using namespace std;
class ChocolateDividingEasy {
	public:
		int n,m;
		int sum[N][N];
		int findBest (vector<string> chocolate) {
			n = chocolate.size();
			m = chocolate[0].size();
			memset(sum, 0, sizeof(sum));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					sum[i][j] = chocolate[i][j] - '0';
					if (i > 0) {
						sum[i][j] += sum[i - 1][j];
					}
					if (j > 0) {
						sum[i][j] += sum[i][j - 1];
					}	
					if (i > 0 && j > 0) {
						sum[i][j] -= sum[i - 1][j - 1];
					}
				}
			}
			int ans = 0;
			for (int r1 = 0; r1 < n - 2; ++r1) {
				for (int r2 = r1 + 1; r2 < n - 1; ++r2) {
					for (int c1 = 0; c1 < m - 2; ++c1) {
						for (int c2 = c1 + 1; c2 < m - 1; ++c2) {
							int maxVal = inf;
							maxVal = min(maxVal, sum[r1][c1]);
							maxVal = min(maxVal, sum[r1][c2] - sum[r1][c1]);
							maxVal = min(maxVal, sum[r1][m - 1] - sum[r1][c2]);
							maxVal = min(maxVal, sum[r2][c1] - sum[r1][c1]);
							maxVal = min(maxVal, sum[r2][c2] - sum[r1][c2] - sum[r2][c1] + sum[r1][c1]);
							maxVal = min(maxVal, sum[r2][m - 1] - sum[r1][m - 1] - sum[r2][c2] + sum[r1][c2]);
							maxVal = min(maxVal, sum[n - 1][c1] - sum[r2][c1]);
							maxVal = min(maxVal, sum[n - 1][c2] - sum[r2][c2] - sum[n - 1][c1] + sum[r2][c1]);
							maxVal = min(maxVal, sum[n - 1][m - 1] - sum[r2][m - 1] - sum[n - 1][c2] + sum[r2][c2]);  
							ans = max(ans, maxVal);
						}
					}
				}
			}
			return ans;
		}
};
