#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll inf = 1LL << 60;
struct matrix {
	ll mat[N][N];
};
class NegativeGraphDiv1 {
	public:
		ll dis[N][N];
		int m, n;
		matrix multi (matrix ma, matrix mb) {
			matrix mc;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					mc.mat[i][j] = (i == j ? 0 : inf);
					for (int k = 0; k < n; ++k) {
						mc.mat[i][j] = min(mc.mat[i][j], ma.mat[i][k] + mb.mat[k][j]);
					}
				}
			}
			return mc;
		}
		matrix solve(matrix mt, int pw) {
			matrix res;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					res.mat[i][j] = (i == j ? 0 : inf);
				}
			}
			while(pw) {
				if (pw & 1) {
					res = multi(res, mt);
				}
				mt = multi(mt, mt);
				pw /= 2;
			}
			return res;
		}
		ll findMin(int nn, vector <int> from, vector <int> to, vector <int> weight, int charges) {
			m = from.size();
			n = nn;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = (i == j ? 0 : inf);
				}
			}
			for (int i = 0; i < m; ++i) {
				int u = from[i] - 1;
				int v = to[i] - 1;
				int w = weight[i];
				dis[u][v] = min(dis[u][v], (ll)w);
			}
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			if (charges == 0) return dis[0][n - 1];
			matrix mt;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					mt.mat[i][j] = dis[i][j];
					for (int k = 0; k < m; ++k) {
						int u = from[k] - 1;
						int v = to[k] - 1;
						int w = weight[k];
						mt.mat[i][j] = min(mt.mat[i][j], dis[i][u] - (ll)w + dis[v][j]);
					}
				}
			}
			mt = solve(mt, charges);
			return mt.mat[0][n - 1];
		}
};
