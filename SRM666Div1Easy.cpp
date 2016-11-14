#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class WalkOverATree {
	public:
		int dp[N][2*N][2];
		int n, L;
		vector<int> edges[N];
		void dfs(int cur, int par) {
			dp[cur][0][0] = dp[cur][0][1] = 1;
			for (int i = 0; i < edges[cur].size(); ++i) {
				int nxt = edges[cur][i];
				if (nxt == par) continue;
				dfs(nxt, cur);
				for (int s = L; s >= 0; --s) {
					for (int t = 0; t <= L; ++t) {
						if (dp[cur][s][0] >= 0) {
							if (s + t + 2 <= L && dp[nxt][t][0] >= 0) 
								dp[cur][s + t + 2][0] = max(dp[cur][s + t + 2][0], dp[cur][s][0] + dp[nxt][t][0]);
							if (s + t + 1 <= L && max(dp[nxt][t][0], dp[nxt][t][1]) >= 0) 
								dp[cur][s + t + 1][1] = max(dp[cur][s + t + 1][1], dp[cur][s][0] + max(dp[nxt][t][0], dp[nxt][t][1]));
						}
						if (dp[cur][s][1] >= 0) {
							if (s + t + 2 <= L && dp[nxt][t][0] >= 0) 
								dp[cur][s + t + 2][1] = max(dp[cur][s + t + 2][1], dp[cur][s][1] + dp[nxt][t][0]);
						}
					}
				}
			}
		}
		int maxNodesVisited (vector<int> parent, int _L) {
			L = _L;
			n = parent.size() + 1;
			for (int i = 0; i < parent.size(); ++i) {
				edges[i + 1].push_back(parent[i]);
				edges[parent[i]].push_back(i + 1);
			}
			memset(dp, -1, sizeof(dp));
			dfs(0, -1);
			int ans = 0;
			for (int i = 0; i <= L; ++i) {
				ans = max(ans, max(dp[0][i][0], dp[0][i][1]));
			}
			return ans;
		}
};
