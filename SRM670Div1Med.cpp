#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define inf 1000000000
using namespace std;
class Treestrat {
	public:
		int n;
		int dis[N][N];
		int roundcnt (vector<int> tree, vector<int> A, vector<int> B) {
			n = tree.size() + 1;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) 
					dis[i][j] = (i == j ? 0 : inf);
			for (int i = 0; i < n - 1; ++i) {
				dis[tree[i]][i + 1] = 1;
				dis[i + 1][tree[i]] = 1;
			}
			for (int k = 0; k < n; ++k) 
				for (int i = 0; i < n; ++i) 
					for (int j = 0; j < n; ++j)
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			int ans = inf;
			for (int i = 0; i < A.size(); ++i) {
				int tmp = 0;
				for (int j = 0; j < n; ++j) {
					bool ok = true;
					for (int k = 0; k < B.size(); ++k) {
						if (dis[A[i]][j] + dis[B[k]][j] > dis[A[i]][B[k]]) {
							if (dis[A[i]][j] >= dis[B[k]][j]) {
								ok = false;
								break;
							}
						} else {
							if (dis[A[i]][j] - dis[B[k]][j] > 1) {
								ok = false;
								break;
							}
						}
					}
					if (!ok) continue;
					int find = inf;
					for (int k = 0; k < B.size(); ++k) {
						find = min(find, max(dis[A[i]][j], dis[B[k]][j]));
					}
					tmp = max(tmp, find);
				}
				ans = min(ans, tmp);
			}
			return ans;
		}
};
