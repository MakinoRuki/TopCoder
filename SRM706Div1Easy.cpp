#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 22
#define inf 1000000000
#define mp make_pair
using namespace std;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
class MovingCandies {
	public:
		int n, m;
		int dp[N][N][N * N];
		bool vis[N][N][N * N];
		int minMoved(vector<string> t) {
			n = t.size();
			m = t[0].size();
			int c = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (t[i][j] == '#') c++;
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					for (int k = 0; k <= c; ++k) {
						dp[i][j][k] = inf;
					}
				}
			}
			queue<pair<pair<int, int>, int> > Q;
			memset(vis, false, sizeof(vis));
			if (t[0][0] == '.') {
				dp[0][0][0] = 1;
				vis[0][0][0] = true;
				Q.push(mp(mp(0, 0), 0));
			} else {
				dp[0][0][1] = 0;
				vis[0][0][1] = true;
				Q.push(mp(mp(0, 0), 1));
			}
			while (!Q.empty()) {
				pair<pair<int, int>, int> cur = Q.front();
				Q.pop();
				int i = cur.first.first;
				int j = cur.first.second;
				int k = cur.second;
				vis[i][j][k] = false;
				for (int d = 0; d < 4; ++d) {
					int ni = i + dx[d];
					int nj = j + dy[d];
					if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
						if (t[ni][nj] == '.') {
							if (k + dp[i][j][k] + 1 <= c) {
								if (dp[i][j][k] + 1 < dp[ni][nj][k]) {
									dp[ni][nj][k] = dp[i][j][k] + 1;
									if (!vis[ni][nj][k]) {
										vis[ni][nj][k] = true;
										Q.push(mp(mp(ni, nj), k));
									}
								}
							}
						} else {
							if (k + dp[i][j][k] + 1 <= c) {
								if (dp[ni][nj][k + 1] > dp[i][j][k]) {
									dp[ni][nj][k + 1] = dp[i][j][k];
									if (!vis[ni][nj][k + 1]) {
										vis[ni][nj][k + 1] = true;
										Q.push(mp(mp(ni, nj), k + 1));
									}
								}
							}
						}
					}
				}
			}
			int ans = inf;
			for (int i = 0; i <= c; ++i) {
				if (dp[n - 1][m - 1][i] < inf && i + dp[n - 1][m - 1][i] <= c) {
					ans = min(ans, dp[n - 1][m - 1][i]);
				}
			}	
			return (ans >= inf ? -1 : ans);
		}
};
