#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define inf 1000000000
using namespace std;
class Gperm {
	public:
		int m;
		vector<int> edges[N];
		int countfee (vector<int> x, vector<int> y) {
			m = x.size();
			for (int i = 0; i < m; ++i) {
				edges[x[i]].push_back(i);
				edges[y[i]].push_back(i);
			}
			int dp[(1<<m)];
			for (int i = 0; i < (1<<m); ++i) {
				dp[i] = inf;
			}
			dp[0] = 0;
			for (int i = 1; i < (1<<m); ++i) {
				int cost = 0;
				for (int j = 0; j < m; ++j) {
					if ((1<<j) & i) cost++;
				}
				for (int j = 0; j < m; ++j) {
					if ((1<<j) & i) {
						int u = x[j];
						int ns = i;
						for (int k = 0; k < edges[u].size(); ++k) {
							int v = edges[u][k];
							if ((1<<v) & ns) {
								ns ^= (1<<v);
							}
						}
						dp[i] = min(dp[i], dp[ns] + cost);
						u = y[j];
						ns = i;
						for (int k = 0; k < edges[u].size(); ++k) {
							int v = edges[u][k];
							if ((1<<v) & ns) {
								ns ^= (1<<v);
							}
						}
						dp[i] = min(dp[i], dp[ns] + cost);
					}
				}
			}
			return dp[(1<<m) - 1];
		}
};

/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define mp make_pair
#define pii pair<int, int>
using namespace std;
class Gperm {
	public:
		int n = 50;
		int m;
		bool vis[N];
		int deg[N];
		vector<int> edges[N];
		vector<int> cad;
		int dfs (bool * vis, int ecnt) {
			vector<int> pts;
			int tmp = 1000000000;
			for (int i = 0; i < cad.size(); ++i) {
				int u = cad[i];
				if (!vis[u]) {
					int tot = 0;
					for (int j = 0; j < edges[u].size(); ++j) {
						if (vis[edges[u][j]]) tot += 2;
						else tot++;
					}
					if (tot < tmp) {
						tmp = tot;
						pts.clear();
						pts.push_back(u);
					} else if (tot == tmp) {
						pts.push_back(u);
					}
				}
			}
			if (pts.size() == 0) return 0;
			int res = 1000000000;
			for (int i = 0; i < pts.size(); ++i) {
			
					int tot = 0;
					int u = pts[i];
					int loop = 0;
					for (int j = 0; j < edges[u].size(); ++j) {
						if (vis[edges[u][j]]) tot++;
						else if (edges[u][j] == u) loop++;
					}
					tot += loop / 2;
					vis[u] = true;
					res = min(res, tot + ecnt + dfs(vis, ecnt + tot));
					vis[u] = false;
			}
			return res;
		}
		int countfee(vector<int> x, vector<int> y) {
			m = x.size();
			memset(vis, false, sizeof(vis));
			for (int i = 0; i < m; ++i) {
				deg[x[i]]++;
				deg[y[i]]++;
				edges[x[i]].push_back(y[i]);
				edges[y[i]].push_back(x[i]);
			}
			cad.clear();
			vector<pii> rank;
			rank.clear();
			for (int i = 0; i < n; ++i) {
				if (deg[i]) {
					cad.push_back(i);
					rank.push_back(mp(deg[i], i));
				}
			}
			sort(rank.begin(), rank.end());
			return dfs(vis, 0);
		}
};*/
