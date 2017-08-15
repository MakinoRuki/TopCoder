#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
class OwaskiAndTree {
	public:
		int n;
		int sum[N], dp[N];
		int maximalScore (vector<int> par, vector<int> plr) {
			n = plr.size();
			memset(sum, 0, sizeof(sum));
			memset(dp, 0, sizeof(dp));
			for (int i = n - 1; i >= 0; --i) {
				sum[i] += plr[i];
				if (sum[i] < 0) sum[i] = 0;
        // 要么是带根结点的sum，要么是不带根结点的dp值求和。不可能两者混合，因为子节点的dp值也是sum得来的。
				dp[i] = max(dp[i], sum[i]);
				if (i) {
					sum[par[i - 1]] += sum[i];
					dp[par[i - 1]] += dp[i];
				}
			}
			return dp[0];
		}
};
