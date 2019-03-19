#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 52
using namespace std;
class MovingTokens {
	public:
		bool can[N][N];
		bool vis[N];
		int move(int n, int m, vector <int> moves) {
			memset(can, false, sizeof(can));
			queue<int> q;
			for (int i = 0; i < n; ++i) {
				can[i][i] = true;
				q.push(i * n + i);
			}
			while(!q.empty()) {
				int a = q.front() / n;
				int b = q.front() % n;
				q.pop();
				for (int r = 0; r < m; ++r) {
					for (int i = 0; i < n; ++i) {
						if (moves[r * n + i] != a) continue;
						for (int j = 0; j < n; ++j) {
							if (moves[r * n + j] == b && !can[i][j]) {
								can[i][j] = can[j][i] = true;
								q.push(i * n + j);
							}
						}
					}
				}
			}
			memset(vis, false, sizeof(vis));
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				if (!vis[i]) {
					vis[i] = true;
					ans++;
					for (int j = 0; j < n; ++j) {
						if (!vis[j] && can[i][j]) {
							vis[j] = true;
							for (int k = 0; k < n; ++k) {
								if (!can[j][k]) can[i][k] = false;
							}
						}
					}
				}
			}
			return ans;
		}
};
