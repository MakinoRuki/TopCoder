#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
bool cmp (const pii & p1, const pii & p2) {
	return p1.first * p2.second > p1.second * p2.first;
}
class Moneymanager {
	public:
		int n;
		vector<pii> rank;
		int dp[2][N][N * 5];
		int getbest (vector<int> a, vector<int> b, int X) {
			n = a.size();
			rank.clear();
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				rank.push_back(mp(a[i], b[i]));
			}
			sort(rank.begin(), rank.end(), cmp);
			reverse(rank.begin(), rank.end());
			for (int ps = 0; ps <= n / 2 * 10; ++ps) {
				memset(dp, -1, sizeof(dp));
				int now = 0;
				int totb = 0;
				dp[0][0][0] = 0;
				for (int i = 0; i < n; ++i) {
					memset(dp[now ^ 1], -1, sizeof(dp[now ^ 1]));
					int ca = rank[i].first;
					int cb = rank[i].second;
					totb += cb;
					for (int j = 0; j <= i; ++j) {
						for (int s = 0; s <= j * 10; ++s) {
							if (dp[now][j][s] < 0) continue;
							if (j + 1 <= n / 2 && (s + cb <= n / 2 * 10)) {
								dp[now ^ 1][j + 1][s + cb] = max(dp[now ^ 1][j + 1][s + cb], dp[now][j][s] + ca * (cb + s));
							}
							if (i + 1 - j <= n / 2) {
								dp[now ^ 1][j][s] = max(dp[now ^ 1][j][s], dp[now][j][s] + ca * (totb - s + ps));
							}
						}
					}
					now ^= 1;
				}
				if (dp[n & 1][n / 2][ps] >= 0) {
					ans = max(ans, dp[n & 1][n / 2][ps] + X * ps);
				}
			}
			return ans;
		}
};
