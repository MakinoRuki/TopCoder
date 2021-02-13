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
#define eps 1e-7
#define M 21
#define N 30
#define SZ 200000002
using namespace std;
typedef long long ll;
class PoisonedSwamp {
public:
	const int inf = 1000000000;
	int dis[N][N];
	bool vis[N][N];
	int n, m;
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	string cross(vector<string> sw) {
		n = sw.size();
		m = sw[0].size();
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				dis[i][j] = inf;
				vis[i][j] = false;
			}
		}
		dis[0][0]=0;
		vis[0][0]=true;
		queue<int> q;
		q.push(0);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			int x=u/m;
			int y=u%m;
			vis[x][y]=false;
			if (dis[x][y] <= 9) {
				for (int d = 0;d < 4; ++d) {
					int nx = x+dx[d];
					int ny=y+dy[d];
					if (nx>=0 && nx<n && ny>=0 && ny<m && sw[nx][ny] != '#') {
						int add = 0;
						if (sw[nx][ny] >= '1' && sw[nx][ny]<='9') {
							add += sw[nx][ny]-'0';
						}
						int nd = dis[x][y]+add;
						if (sw[nx][ny]=='S') nd= 0;
						if (dis[nx][ny] > nd) {
							dis[nx][ny] = nd;
							if (!vis[nx][ny]) {
								vis[nx][ny]=true;
								q.push(nx*m+ny);
							}
						}
					}
				}
			}
		}
		if (dis[n-1][m-1]<=9) {
			return "possible";
		}
		return "impossible";
	}
};
