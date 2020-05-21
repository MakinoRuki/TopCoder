#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class BoxTower {
	public:
		int n;
		int dp[1<<15][15][3];
		int tallestTower(vector<int> x, vector<int> y, vector<int> z) {
			n = x.size();
			memset(dp,0,sizeof(dp));
			for (int i = 0; i < n; ++i) {
				dp[1<<i][i][0] = x[i];
				dp[1<<i][i][1] = y[i];
				dp[1<<i][i][2] = z[i];
			}
			for (int i = 1; i < (1<<n); ++i) {
				for (int j = 0; j < n; ++j) {
					if (!((1<<j)&i)) continue;
					for (int k = 0; k < 3; ++k) {
						if (dp[i][j][k] > 0) {
							for (int j2 = 0; j2 < n; ++j2) {
								if ((1<<j2)&i) continue;
								for (int k2 = 0; k2 < 3; ++k2) {
									int x1,y1,x2,y2;
									if (k==0) x1=y[j],y1=z[j];
									else if (k==1) x1=x[j], y1=z[j];
									else x1 = x[j], y1=y[j];
									if (k2==0) x2=y[j2],y2=z[j2];
									else if (k2==1) x2=x[j2], y2=z[j2];
									else x2 = x[j2], y2=y[j2];
									if ((x1 <= x2 && y1 <= y2) || (x1 <= y2 && y1 <= x2)) {
										int ht = (k2 == 0 ? x[j2] : (k2 == 1 ? y[j2] : z[j2]));
										dp[i|(1<<j2)][j2][k2] = max(dp[i|(1<<j2)][j2][k2], dp[i][j][k] + ht);
									}
								}
							}
						}
					}
				}
			}
			int ans=0;
			for (int i = 0; i < (1<<n); ++i) {
				for (int j = 0; j < n; ++j) {
					for (int k = 0; k < 3; ++k) {
						ans = max(ans, dp[i][j][k]);
					}
				}
			}
			return ans;
		}
};
