#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define N 52
typedef long long ll;
using namespace std;
class FlightPlan {
public:
	ll dis[N][N][N][N];
	bool vis[N][N][N][N];
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	ll fly(int r, int c, vector<int> h, int cp, int cd, int clr) {
		for (int i = 0; i <= r; ++i) {
			for (int j = 0; j <= c; ++j) {
				for (int i2 = 0; i2 <= r; ++i2) {
					for (int j2 = 0; j2 <= c; ++j2) {
						dis[i][j][i2][j2] = (1LL<<60)-1;
					}
				}
			}
		}
		dis[0][0][0][0] = 0LL;
		memset(vis, false, sizeof(vis));
		vis[0][0][0][0] = true;
		queue<pair<pair<int,int>, pair<int,int>>> q;
		q.push(make_pair(make_pair(0,0), make_pair(0,0)));
		while(!q.empty()) {
			auto pr = q.front();
			q.pop();
			int x=pr.first.first;
			int y=pr.first.second;
			int x2=pr.second.first;
			int y2=pr.second.second;
			vis[x][y][x2][y2] = false;
			if (x==r-1 && y == c-1) {
				continue;
			}
			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx>=0 && nx < r && ny >=0 && ny< c) {
					if (h[x2*c+y2] >= h[nx*c+ny]) {
						if (dis[nx][ny][x2][y2] > dis[x][y][x2][y2]+clr) {
							dis[nx][ny][x2][y2] = dis[x][y][x2][y2]+clr;
							if (!vis[nx][ny][x2][y2]) {
								vis[nx][ny][x2][y2] = true;
								q.push(make_pair(make_pair(nx,ny), make_pair(x2,y2)));
							}
						}
					} else {
						ll det = h[nx*c+ny] - h[x2*c+y2];
						if (dis[nx][ny][nx][ny] > dis[x][y][x2][y2]+clr+det*(ll)cp) {
							dis[nx][ny][nx][ny] = dis[x][y][x2][y2]+clr+det*(ll)cp;
							if (!vis[nx][ny][nx][ny]) {
								vis[nx][ny][nx][ny] = true;
								q.push(make_pair(make_pair(nx, ny), make_pair(nx, ny)));
							}
						}
					}
				}
			}
		}
		ll ans = (1LL<<60)-1;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (h[i*c+j] >= h[(r-1)*c+c-1] && dis[r-1][c-1][i][j] < (1LL<<60)-1) {
					ll cst = dis[r-1][c-1][i][j];
					if (h[i*c+j] > h[(r-1)*c+c-1]) {
						ll det=h[i*c+j]-h[(r-1)*c+c-1];
						cst += det*(ll)cd;
					}
					ans = min(ans, cst);
				}
			}
		}
		return ans;
	}
};
