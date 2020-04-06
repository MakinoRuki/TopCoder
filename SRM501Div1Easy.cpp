#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define N 52
using namespace std;
typedef long long ll;
class FoxPlayingGame {
public:
	double dp[2][N][N];
	double theMax(int na, int nb, int pa, int pb) {
		double sa = (double)pa / 1000.0;
		double sb = (double)pb / 1000.0;
		for (int i = 0; i <= na; ++i) {
			for (int j = 0; j <= nb; ++j) {
				dp[0][i][j] = -(double)(1LL<<60);
				dp[1][i][j] = (double)(1LL<<60);
			}
		}
		// max
		dp[0][0][0] = 0.0;
		// min
		dp[1][0][0] = 0.0;
		for (int i = 0; i <= na; ++i) {
			for (int j = 0; j <= nb; ++j) {
				if (i+1<=na) {
					dp[0][i+1][j] = max(dp[0][i+1][j], dp[0][i][j]+sa);
					dp[1][i+1][j] = min(dp[1][i+1][j], dp[1][i][j]+sa);
				}
				if (j+1<=nb) {
					if (sb > 0) {
						dp[0][i][j+1] = max(dp[0][i][j+1], dp[0][i][j]*sb);
						dp[1][i][j+1] = min(dp[1][i][j+1], dp[1][i][j]*sb);
					} else {
						dp[0][i][j+1] = max(dp[0][i][j+1], dp[1][i][j]*sb);
						dp[1][i][j+1] = min(dp[1][i][j+1], dp[0][i][j]*sb);
					}
				}
			}
		}
		return dp[0][na][nb];
	}
};
