#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
class MonstersAndBunnies {
	public:
		double dp[N][N];
		double survivalProbability(int m, int b) {
			for (int j = 0; j <= b; ++j) {
				dp[0][j] = 1.0;
			}
			dp[1][0] = 0.0;
			for (int i= 2; i <= m; ++i) {
				dp[i][0] = dp[i-2][0] * (double)(i-1)/(double)(i+1);
			}
			for (int i = 1; i <= m; ++i) {
				for (int j = 1; j <= b; ++j) {
					double x = (double)(i+j+1)*(i+j);
					double sum = dp[i][j-1]*2.0*i*j/x;
					if (i >= 2) {
						sum += dp[i-2][j]*(double)i*(double)(i-1)/x;
					}
					double pr = 1.0 - 2.0*j/x - (double)j*(j-1)/x;
					dp[i][j] = sum / pr;
					sum += dp[i][j-1]*2.0*j/x;
					pr = 1.0 - (double)j*(j-1)/x;
					if (sum / pr > dp[i][j]) dp[i][j] = sum/pr;
				}
			}
			return dp[m][b];
		}
};
