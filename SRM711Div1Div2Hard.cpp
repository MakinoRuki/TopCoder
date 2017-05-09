#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 302
#define mp make_pair
#define pii pair<int, int>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class TreeMoving {
	public:
		vector<pii> edges[N][N];
		int n, m;
		ll dp[N][N];
		vector<pii> edges2[N];
		vector<int> rank[N];
		int par[N][N];
		int pare[N][N];
		int level[N][N];
		int lca[N][N];
		void update (ll & a, ll b) {
			a = (a + b) % mod;
		}
		void dfs (int idx, int cur, int p, int lev) {
			par[idx][cur] = p;
			level[idx][cur] = lev;
			for (int i = 0; i < edges[idx][cur].size(); ++i) {
				if (edges[idx][cur][i].first == p) {
					pare[idx][cur] = edges[idx][cur][i].second;
				} else {
					dfs(idx, edges[idx][cur][i].first, cur, lev + 1);
				}
			}
			rank[idx].push_back(cur);
		}
		int count (int nn, vector<int> rs, vector<int> a, vector<int> b, vector<int> c) {
			n = nn;
			m = rs.size();
			vector<int> X;
			X.clear();
			for (int i = 0; i < m; ++i) {
				X.clear();
				X.push_back(c[i]);
				for (int k = 1; k < n - 1; ++k) {
					X.push_back(((ll)a[i] * (ll)X[k - 1] % mod + (ll)b[i]) % mod);
				}
				for (int j = 0; j < n - 1; ++j) {
					int u = (rs[i] + j + 1) % n;
					int v = (rs[i] + (X[j] % (j + 1))) % n;
					edges[i][u].push_back(mp(v, j));
					edges[i][v].push_back(mp(u, j));
					edges2[i].push_back(mp(u, v));
				}
				dfs(i, 0, -1, 0);
			}
			for (int j = 0; j < m; ++j) {
				for (int k = 0; k < n - 1; ++k) {
					int u = edges2[j][k].first;
					int v = edges2[j][k].second;
					int nj = (j + 1) % m;
					while (level[nj][u] > level[nj][v]) u = par[nj][u];
					while (level[nj][v] > level[nj][u]) v = par[nj][v];
					while (u != v) {
						u = par[nj][u];
						v = par[nj][v];
					}
					lca[j][k] = u;
				}
			}
			ll ans = 0LL;
			for (int i = 0; i < n - 1; ++i) {
				memset(dp, 0LL, sizeof(dp));
				dp[0][i] = 1LL;
				for (int j = 0; j < m; ++j) {
					vector<ll> sum(n, 0LL);
					for (int k = 0; k < n - 1; ++k) {
						int u = edges2[j][k].first;
						int v = edges2[j][k].second;
						update(sum[u], dp[j][k]);
						update(sum[v], dp[j][k]);
						update(sum[lca[j][k]], -dp[j][k] + mod);
						update(sum[lca[j][k]], -dp[j][k] + mod);
					}
					for (int k = 0; k < rank[(j + 1) % m].size(); ++k) {
						int udx = rank[(j + 1) % m][k];
						if (udx == 0) continue;
						update(dp[j + 1][pare[(j + 1) % m][udx]], sum[udx]);
						update(sum[par[(j + 1) % m][udx]], sum[udx]);
					}
				}
				update(ans, dp[m][i]);
			}
			return ans;
		}
};
