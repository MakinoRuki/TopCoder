#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
class BearSpans {
	public:
		vector<int> ans;
		bool mat[N][N];
		vector<int> findAnyGraph(int n, int m, int k) {
			ans.clear();
			vector<int> pts[2];
			pts[0].clear();
			for (int i = 1; i <= n; ++i) {
				pts[0].push_back(i);
			}
			memset(mat, false, sizeof(mat));
			int idx = 0;
			for (int i = 1; i <= k; ++i) {
				int now = i & 1;
				pts[now].clear();
				if (pts[now ^ 1].size() == 1) return vector<int>{-1};
				if (idx >= m) return vector<int>{-1};
				if (i < k) {
					for (int j = 0; j < pts[now ^ 1].size(); j += 2) {
						++idx;
						if (j < pts[now ^ 1].size() - 1) {
							int u = pts[now ^ 1][j];
							int v = pts[now ^ 1][j + 1];
							ans.push_back(u);
							ans.push_back(v);
							pts[now].push_back(u);
							mat[u][v] = mat[v][u] = true;
						} else {
							int u = pts[now ^ 1][0];
							int v = pts[now ^ 1][j];
							ans.push_back(u);
							ans.push_back(v);
							mat[v][u] = mat[u][v] = true;
						}	
					}
				} else {
					for (int j = 1; j < pts[now ^ 1].size(); ++j) {
						++idx;
						int u = pts[now ^ 1][j - 1];
						int v = pts[now ^ 1][j];
						ans.push_back(u);
						ans.push_back(v);
						mat[u][v] = mat[v][u] = true;
					}
				}	
			}
			if (idx < m) {
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						if (i == j || mat[i][j]) continue;
						++idx;
						if (idx > m) continue;
						ans.push_back(i);
						ans.push_back(j);
						mat[i][j] = mat[j][i] = true;
					}
				}
			}
			return ans;
		}
};
