#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1<<20
using namespace std;
bool dp[(N) + 2];
class DistinguishableSetDiv1 {
	public:
		int n, m;
		int count (vector<string> answer) {
			n = answer.size();
			m = answer[0].size();
			memset(dp, false, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					int stat = 0;
					for (int k = 0; k < m; ++k) {
						if (answer[i][k] == answer[j][k]) {
							stat += (1<<k);
						}
					}
					dp[stat] = true;
				}
			}
			int ans = 0;
			for (int i = (1<<m) - 1; i >= 0; --i) {
				if (!dp[i]) {
					ans++;
				} else {
					for (int j = 0; j < m; ++j) {
						if ((1<<j) & i) {
							dp[i ^ (1<<j)] = true;
						}
					}
				}
			}
			return ans;
		}
};
