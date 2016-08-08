#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
int mat[N][N];
class BearSpans {
	public:
		vector<int> findAnyGraph (int n, int m, int k) {
			vector<int> roots;
			roots.clear();
			for (int i = 0; i < n; ++i) {
				roots.push_back(i);
			}
			memset(mat, 0, sizeof(mat));
			int cnt = 0;
			for (int i = 1; i < k; ++i) {
				if (roots.size() <= 1) {
					return {-1};
				}
				vector<int> tmp;
				tmp.clear();
				for (int j = 0; j < roots.size(); j += 2) {
					if (j + 1 >= roots.size()) break;
					int u = roots[j];
					int v = roots[j + 1];
					mat[u][v] = mat[v][u] = ++cnt;
					tmp.push_back(u);
				}
				if (roots.size() & 1) {
					int u = roots[roots.size() - 2];
					int v = roots[roots.size() - 1];
					mat[u][v] = mat[v][u] = ++cnt;
				}
				roots = tmp;
			}
			if (roots.size() <= 1) return {-1};
			for (int i = 1; i < roots.size(); ++i) {
				int u = roots[i - 1];
				int v = roots[i];
				mat[u][v] = mat[v][u] = ++cnt;
			}
			vector<int> ans (2 * m, 0);
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					if (mat[i][j]) {
						int num = mat[i][j];
						ans[2 * num - 2] = i + 1;
						ans[2 * num - 1] = j + 1;
					} else {
						++cnt;
						if (cnt > m) continue;
						mat[i][j] = mat[j][i] = cnt;
						ans[2 * cnt - 2] = i + 1;
						ans[2 * cnt - 1] = j + 1;
					}
				}
			}
			return ans;
		}
};
