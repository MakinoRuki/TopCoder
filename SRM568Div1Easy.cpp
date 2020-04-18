#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define N 52
using namespace std;
typedef long long ll;
class BallsSeparating {
public:
	int dp[N][1<<3];
	int n;
	int minOperations(vector<int> r, vector<int> g, vector<int> b) {
		n = r.size();
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j < (1<<3); ++j) {
				dp[i][j] = 1000000000;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (1<<3); ++j) {
				if (dp[i][j] < 1000000000) {
					dp[i+1][j|1] = min(dp[i+1][j|1], dp[i][j]+g[i]+b[i]);
					dp[i+1][j|2] = min(dp[i+1][j|2], dp[i][j]+r[i]+b[i]);
					dp[i+1][j|4] = min(dp[i+1][j|4], dp[i][j]+r[i]+g[i]);
				}
			}
		}
		int s=0;
		for (int i = 0; i < n; ++i) {
			if (r[i]>0) s|=1;
			if (g[i]>0) s|=2;
			if (b[i]>0) s|=4;
		}
		int ans=1000000000;
		for (int i = 0; i < (1<<3); ++i) {
			if ((i&s)==s) {
				ans = min(ans, dp[n][i]);
			}
		}
		return (ans < 1000000000 ? ans : -1);
	}
};
