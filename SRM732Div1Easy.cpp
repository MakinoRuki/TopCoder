#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 22
#define inf 1000000000
using namespace std;
class TileFlippingGame {
	public:
		int col[N][N];
		int part[N][N];
		int dis[N][N];
		bool vis[N][N];
		int cnt;
		int n, m;
		int dx[4] = {-1, 1, 0, 0};
		int dy[4] = {0, 0, -1, 1};
		vector<string> Y;
		int ans[N * N][2];
		void dfs(int x, int y) {
			part[x][y] = cnt;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && Y[nx][ny] != 'e' && !part[nx][ny]) {
					dfs(nx, ny);
				}
			}
		}
		void solve(int x, int y) {
			queue<int> Q;
			int idx = part[x][y];
			memset(vis, false, sizeof(vis));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					dis[i][j] = inf;
					if (i == x && j == y) {
						dis[i][j] = 0;
						Q.push(i * m + j);
						vis[i][j] = true;
					}
				}
			}
			while(!Q.empty()) {
				int cur = Q.front();
				Q.pop();
				int x = cur / m;
				int y = cur % m;
				vis[x][y] = false;
				for (int i = 0; i < 4; ++i) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (nx >= 0 && nx < n && ny >= 0 && ny < m && Y[nx][ny] != 'e') {
						int nd = dis[x][y];
						if (Y[nx][ny] != Y[x][y]) {
							nd++;
						}
						if (nd < dis[nx][ny]) {
							dis[nx][ny] = nd;
							if (!vis[nx][ny]) {
								vis[nx][ny] = true;
								Q.push(nx * m + ny);
							}
						}
					}
				}
			}
			int res = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (part[i][j] == part[x][y]) {
					//	if (x == 2) cout<<i<<" "<<j<<endl<<dis[i][j]<<endl;
						res = max(res, dis[i][j]);
					}
				}
			}
			ans[idx][(col[x][y] + res) % 2] = min(ans[idx][(col[x][y] + res) % 2], res);
			ans[idx][(col[x][y] + res + 1) % 2] = min(ans[idx][(col[x][y] + res + 1) % 2], res + 1);
		}
		int HowManyMoves(int nn, int mm, vector<string> X) {
			Y = X;
			n = nn;
			m = mm;
			memset(col, -1, sizeof(col));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (X[i][j] == 'b') col[i][j] = 1;
					else if (X[i][j] == 'w') col[i][j] = 0;
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (X[i][j] != 'e' && !part[i][j]) {
						++cnt;
						dfs(i, j);
					}
				}
			}
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j <= cnt; ++j) {
					ans[j][i] = inf;
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (X[i][j] != 'e') {
						solve(i, j);
					}
				}
			}
			//cout<<ans[1][0]<<" "<<ans[1][1]<<" "<<ans[2][0]<<" "<<ans[2][1]<<endl;
			int tot0 = 0, tot1 = 0;
			for (int i = 1; i <= cnt; ++i) {
				tot0 += ans[i][0];
				tot1 += ans[i][1];
			}
			return min(tot0, tot1);
		}
};
