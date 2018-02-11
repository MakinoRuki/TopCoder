#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 1002
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
class FrogSquare {
	public:
		vector<pii> pos;
		int dis[4 * N];
		bool getdis(int x1, int y1, int x2, int y2, int d) {
			return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) >= d * d;
		}
		int minimalJumps (int n, int d, int sx, int sy, int tx, int ty) {
			if (sx == tx && sy == ty) return 0;
			pos.clear();
			int m = 0;
			pos.push_back(make_pair(sx, sy));
			pos.push_back(make_pair(tx, ty));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i != 0 && i != n - 1 && j != 0 && j != n - 1) continue;
					if (i == sx && j == sy) continue;
					if (i == tx && j == ty) continue;
					pos.push_back(make_pair(i, j));
				}
			}
			m = pos.size();
			for (int i = 0; i < m; ++i) {
				dis[i] = inf;
			}
			dis[0] = 0;
			queue<int> Q;
			Q.push(0);
			while(!Q.empty()) {
				int u = Q.front();
				Q.pop();
				for (int i = 0; i < m; ++i) {
					if (getdis(pos[u].first, pos[u].second, pos[i].first, pos[i].second, d)) {
						if (dis[u] + 1 < dis[i]) {
							dis[i] = dis[u] + 1;
							Q.push(i);
						}
					} 
				}
			}
			return dis[1] == inf ? -1 : dis[1];
		}
};
