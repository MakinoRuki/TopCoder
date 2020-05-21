#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 42
using namespace std;
class NumberofFiboCalls {
	public:
		int dp[N];
		vector<int> fiboCallsMade(int n) {
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			dp[1] = 0;
			int zn = 0;
			int on = 0;
			for (int i = 2; i <= n; ++i) {
				dp[i] = dp[i-1]+dp[i-2];
			}
			zn = dp[n];
			dp[0] = 0;
			dp[1] = 1;
			for (int i = 2; i <= n; ++i) {
				dp[i] = dp[i-1]+dp[i-2];
			}
			on = dp[n];
			return {zn, on};
		}
};
