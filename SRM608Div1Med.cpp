#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class BigO {
	public:
		int n;
		bool dis[N][N];
		int par[N];
		bool mat[N][N];
		int dp[N];
		int cnt[N];
		int dfs (int cur) {
			if (dp[cur] >= 0) return dp[cur];
			dp[cur] = 0;
			for (int i = 0; i < n; ++i) {
				if (mat[cur][i]) {
					dp[cur] = max(dp[cur], dfs(i));
				}
			}
			if (cnt[cur] > 1) dp[cur]++;
			return dp[cur];
		}
		int minK (vector<string> graph) {
			n = graph.size();
			memset(dis, false, sizeof(dis));
			for (int i = 0; i < n; ++i) {
				par[i] = i;
				for (int j = 0; j < n; ++j) {
					if (graph[i][j] == 'Y') dis[i][j] = true;
				}
			}
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						dis[i][j] |= (dis[i][k] & dis[k][j]);
					}
				}
			}
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n; ++i) {
				if (par[i] == i) {
					cnt[i]++;
					for (int j = i + 1; j < n; ++j) {
						if (dis[i][j] && dis[j][i]) {
							par[j] = i;
							cnt[i]++;
						}	
					}
				}
			}
		//	for (int i = 0; i < n; ++i) cout<<i<<" "<<par[i]<<endl;
			for (int i = 0; i < n; ++i) {
				int in = 0, out = 0;
				for (int j = 0; j < n; ++j) {
					if (i != j && par[i] == par[j] && graph[j][i] == 'Y') in++;
					if (i != j && par[i] == par[j] && graph[i][j] == 'Y') out++;
				}
				if (in > 1 || out > 1) return -1;
			}	
			memset(mat, false, sizeof(mat));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (par[i] != par[j] && graph[i][j] == 'Y') {
						mat[par[i]][par[j]] = true;
					}
				}
			}
			memset(dp, -1, sizeof(dp));
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				if (dp[par[i]] < 0) ans = max(ans, dfs(par[i]));
			}
			return max(ans - 1, 0);
		}
};
