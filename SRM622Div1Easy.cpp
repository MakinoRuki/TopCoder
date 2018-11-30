#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class BuildingRoutes {
	public:
		int n;
		int dis[N][N];
		int build(vector <string> dist, int T) {
			n = dist.size();
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dis[i][j] = dist[i][j] - '0';
				}
			}
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
					}
				}
			}
			int ans = 0;
			for (int a = 0; a < n; ++a) {
				for (int b = 0; b < n; ++b) {
					if (a == b) continue;
					int cnt = 0;
					for (int i = 0; i < n; ++i) {
						for (int j = 0; j < n; ++j) {
							if (i == j) continue;
							if (dis[i][a] + dist[a][b] - '0' + dis[b][j] == dis[i][j]) cnt++;
						}
					}
					if (cnt >= T) ans += dist[a][b] - '0';
				}
			}
			return ans;
		}
};
