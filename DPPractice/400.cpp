#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll dp[N][N];
class HandsShaking {
	public:
		ll countPerfect(int n) {
			memset(dp, 0, sizeof(dp));
			for (int i = n; i >= 1; --i) {
				for (int j = i + 1; j <= n; ++j) {
					if (j==i+1) dp[i][j] =1;
					else {
						if ((j-i+1)%2==0) {
							dp[i][j] += dp[i+2][j];
							dp[i][j] += dp[i+1][j-1];
							for (int k = i + 3; k < j; k+=2) {
								dp[i][j] += dp[i+1][k-1]*dp[k+1][j];
							}
						}
					}
				}
			}
			return dp[1][n];
		}
};
