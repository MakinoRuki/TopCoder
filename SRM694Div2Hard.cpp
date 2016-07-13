#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define M 5002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[N][M];
class UpDownNess {
	public:
		int count (int n, int k) {
			memset(dp, 0LL, sizeof(dp));
			dp[1][0] = 1LL;
			for (int i = 1; i < n; ++i) {
				for (int j = 0; j <= k; ++j) {
					for (int pre = 0; pre <= i; ++pre) {
						ll add = pre * (i - pre);
						if (j + add <= k) {
							dp[i + 1][j + add] = (dp[i + 1][j + add] + dp[i][j]) % mod;
						}
					}
				}
			}
			return dp[n][k];
		}
};
