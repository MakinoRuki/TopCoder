#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 502
#define M 10002
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class CtuRobots {
	public:
		vector<pii> robots;
		double dp[2][M];
		bool vis[2][M];
		int n;
		double maxDist (int B, vector<int> cost, vector<int> cap) {
			robots.clear();
			for (int i = 0; i < cost.size(); ++i) {
				robots.push_back(mp(cap[i], cost[i]));
			}
			sort(robots.begin(), robots.end());
			n = robots.size();
			memset(vis, false, sizeof(vis));
			vis[0][0] = true;
			dp[0][0] = 0.0;
			for (int i = 0; i < n; ++i) {
				int now = i & 1;
				memset(vis[now ^ 1], false, sizeof(vis[now ^ 1]));
				for (int j = 0; j <= B; ++j) {
					dp[now ^ 1][j] = 0.0;
				}
				for (int j = 0; j <= B; ++j) {
					if (vis[now][j]) {
						int co = robots[i].second;
						int ca = robots[i].first;
						if (j + co <= B) {
							dp[now ^ 1][co + j] = max(dp[now ^ 1][co + j], dp[now][j] / 3.0 + (double)ca);
							vis[now ^ 1][co + j] = true;
						}
						dp[now ^ 1][j] = max(dp[now ^ 1][j], dp[now][j]);
						vis[now ^ 1][j] = true;
					}
				}
			}
			double ans = 0.0;
			for (int i = 0; i <= B; ++i) {
				ans = max(ans, dp[n & 1][i]);
			}
			return ans * 0.5;
		}
};
