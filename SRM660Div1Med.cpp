#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class Privateparty {
	public:
		double exp[N][N];
		int ring[N];
		int n;
		bool vis[N];
		double getY (int a, int b, int c) {
			return exp[a + c][0] + exp[b + c][0] - exp[c][0];
		}
		double getexp (vector<int> a) {
			n = a.size();
			exp[0][0] = 0.0;
			exp[1][0] = 1.0;
			exp[0][1] = 1.0;
			for (int i = 2; i <= n; ++i) {
				exp[i][0] = 0.0;
				for (int j = 1; j <= i; ++j) {
					exp[i][0] += exp[max(0, j - 2)][0] + exp[i - j][0] + 1.0;
				}
				exp[i][0] /= (double)i;
			}
			for (int i = 2; i <= n; ++i) {
				exp[0][i] = exp[i - 2][0] + 1.0;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = 2; j <= n; ++j) {
					exp[i][j] = 0.0;
					for (int k = 1; k <= i; ++k) {
						exp[i][j] += exp[max(0, k - 2)][0] + exp[i - k][j] + 1.0;
					}
					exp[i][j] += exp[i - 1][0] + exp[j - 2][0] + 1.0;
					exp[i][j] += exp[i][0] + exp[j - 2][0] + 1.0;
					if (j >= 3) {
						exp[i][j] += exp[i + j - 2][0] + 1.0;
						for (int k = 1; k <= j - 3; ++k) {
							exp[i][j] += getY(i, j - k - 2, k) + 1.0;
						}
					}
					exp[i][j] /= (double)(i + j);
				}
			}
			memset(ring, 0, sizeof(ring));
			for (int i = 0; i < n; ++i) {
				memset(vis, false, sizeof(vis));
				int cur = i;
				int cnt = 1;
				vis[cur] = true;
				while (true) {
					if (a[cur] == cur || vis[a[cur]]) {
						break;
					}
					cur = a[cur];
					vis[cur] = true;
					cnt++;
				}
				if (a[cur] == i && cnt > 1) {
					ring[i] = cnt;
				}
			}
			double ans = 0.0;
			for (int i = 0; i < n; ++i) {
				if (ring[i] > 0) {
					ans += exp[0][ring[i]] / (double)ring[i];
				} else {
					int cnt = 1;
					int cur = i;
					while (true) {
						if (a[cur] == cur || ring[a[cur]] > 0) {
							break;
						}
						cur = a[cur];
						cnt++;
					}
					ans += exp[cnt][ring[a[cur]]] - exp[cnt - 1][ring[a[cur]]];
				}
			}
			return ans;
		}
};
