#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
const int mod = 1000000007;
class SumPyramid {
	public:
		int dp[N];
		int comb[N][N];
		int countPyramids(int lev, int top) {
			memset(comb, 0, sizeof(comb));
			for (int i = 0; i <= lev; ++i) {
				comb[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = min(comb[i - 1][j] + comb[i - 1][j - 1], N);
				}
			}
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int i = 1; i <= lev; ++i) {
				int number = comb[lev - 1][i - 1];
				if (number >= N) continue;
				for (int j = 0; j + number <= top; ++j) {
					dp[j + number] = (dp[j + number] + dp[j]) % mod;
				}
			}
			return dp[top];
		}
};
