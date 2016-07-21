#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 302
#define inf 1000000000
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int dis[N][N];
bool onPath[N];
vector<int> edges[N];
class BearUniqueDiameter {
	public:
		int n;
		ll dfs (int cur, int par, int maxD) {
			ll res = 1LL;
			if (maxD <= 0) return res;
			for (int i = 0; i < edges[cur].size(); ++i) {
				int v = edges[cur][i];
				if (v == par || onPath[v]) continue;
				res = res * ((dfs(v, cur, maxD - 1) + 1LL) % mod) % mod;
			}
			return res;
		}
		int countSubtrees (vector<int> a, vector<int> b) {
			n = a.size() + 1;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = (i == j ? 0 : inf);
				}
			}
			for (int i = 0; i < a.size(); ++i) {
				dis[a[i]][b[i]] = dis[b[i]][a[i]] = 1;
				edges[a[i]].push_back(b[i]);
				edges[b[i]].push_back(a[i]);
			}
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			ll ans = 0LL;
			for (int i = 0; i < n; ++i) {
				for (int j = i; j < n; ++j) {
					if (i == j) ans = (ans + 1LL) % mod;
					else {
						memset(onPath, false, sizeof(onPath));
						for (int k = 0; k < a.size(); ++k) {
							int x = a[k], y = b[k];
							if ((dis[x][i] + dis[j][y] + 1 == dis[i][j]) || (dis[y][i] + dis[x][j] + 1 == dis[i][j])) {
								onPath[x] = true;
								onPath[y] = true;
							}
						}
						ll res = 1LL;
						for (int k = 0; k < n; ++k) {
							if (onPath[k] && k != i && k != j) {
								res = res * dfs(k, -1, min(dis[k][i], dis[k][j]) - 1) % mod;
							}
						}
					//	cout<<i<<" "<<j<<" "<<res<<endl;
						ans = (ans + res) % mod;
					}
				}
			}
			return ans;
		}
};
