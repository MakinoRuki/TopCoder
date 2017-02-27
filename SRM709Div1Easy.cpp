#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Xscoregame {
	public:
		int n;
		int dp[1<<16][1<<6];
		int getscore(vector<int> A) {
			n = A.size();
			memset(dp, -1, sizeof(dp));
			dp[0][0] = 0;
			for (int i = 0; i < (1<<n); ++i) {
				for (int j = 0; j < (1<<6); ++j) {
				if (dp[i][j] >= 0) {
					for (int k = 0; k < n; ++k) {
						if ((1<<k) & i) continue;
						int ni = i | (1<<k);
						int nv = (dp[i][j] + (dp[i][j] ^ A[k]));
						int nj = nv % 64;
						dp[ni][nj] = max(dp[ni][nj], nv);
					}
				}
				}
			}
			int ans = 0;
			for (int i = 0; i < (1<<6); ++i) {
				ans = max(ans, dp[(1<<n) - 1][i]);
			}
			return ans;
		}
};
