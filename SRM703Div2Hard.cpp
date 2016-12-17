#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 1002
using namespace std;
class TreeDiameters {
	public:
		int n;
		vector<int> edges[N];
		int dis[2][N];
		int cnt[2][N];
		bool vis[N];
		int sum[N], tot[N];
		void bfs (int root, int * dis, bool * vis, int * cnt) {
		//	if (root == 0) cout<<"aaa"<<" "<<vis[1]<<" "<<vis[0]<<endl;
			queue<int> Q;
			Q.push(root);
			while (!Q.empty()) {
				int u = Q.front();
				Q.pop();
				for (int i = 0; i < edges[u].size(); ++i) {
					int v = edges[u][i];
					if (!vis[v]) {
						dis[v] = dis[u] + 1;
						vis[v] = true;
						Q.push(v);
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				cnt[dis[i]]++;
			}
		}
		void solve(int u, int v, int d, int c) {
			memset(vis, false, sizeof(vis));
			memset(dis[d], -1, sizeof(dis[d]));
			memset(cnt[c], 0, sizeof(cnt[c]));
			vis[u] = vis[v] = true;
			dis[d][v] = 0;
			bfs(v, dis[d], vis, cnt[c]);
		}
		int getMax (vector<int> p) {
			n = p.size() + 1;
			for (int i = 0; i < p.size(); ++i) {
				edges[i + 1].push_back(p[i]);
				edges[p[i]].push_back(i + 1);
			}
			int ans = 1;
			for (int i = 0; i < n; ++i) {
				memset(sum, 0, sizeof(sum));
				memset(tot, 0, sizeof(tot));
				for (int j = 0; j < edges[i].size(); ++j) {
					int v = edges[i][j];
					solve(i, v, 0, 0);
					for (int k = 0; k < n; ++k) {
						tot[k] += cnt[0][k] * sum[k];
						sum[k] += cnt[0][k];
						ans = max(ans, tot[k]);
					}
				}
			}
			for (int i = 0; i < p.size(); ++i) {
				int u = i + 1;
				int v = p[i];
				solve(v, u, 0, 0);
				solve(u, v, 1, 1);
				for (int j = 1; j < n; ++j) {
					ans = max(ans, cnt[0][j] * cnt[1][j]);
				}
			}
			return ans;
		}
};
