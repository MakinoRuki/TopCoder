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
#define eps 1e-10
#define M 200005
#define N 2502
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
int dp[N][N][2];
//bool vis[N][N][N*N];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
class Jetpack {
public:
	int travel(vector<string> mz, int t) {
		int n = (int)mz.size();
		int m = (int)mz[0].size();
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				for (int k = 0; k < 2; ++k) {
					dp[i][j][k] = inf;
					//vis[i][j][k] = false;
				}
			}
		}
		int sx=0, sy=0, tx=0, ty=0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mz[i][j] == 'A') {
					sx = i;
					sy = j;
				}
				if (mz[i][j] == 'B') {
					tx = i;
					ty = j;
				}
			}
		}
		priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
		dp[sx][sy][0] = 0;
		pq.push(make_pair(0, make_pair(sx*m+sy, 0)));
		while(!pq.empty()) {
			auto pr = pq.top();
			pq.pop();
			int x = pr.second.first/m;
			int y = pr.second.first%m;
			int c = pr.second.second;
			int d = pr.first;
			if (d > dp[x][y][c]) {
				continue;
			}
			if (x == tx && y == ty) {
				return dp[x][y][c];
			}
			// if (mz[x][y] == 'C' && c < n*m) {
			// 	if (dp[x][y][c+1] > dp[x][y][c] + t) {
			// 		dp[x][y][c+1] = dp[x][y][c] +t;
			// 		pq.push(make_pair(dp[x][y][c+1], make_pair(x*m+y, c+1)));
			// 	}
			// }
			for (int dr = 0; dr < 4; ++dr) {
				int nx = x + dx[dr];
				int ny = y + dy[dr];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && mz[nx][ny] != '#') {
					if (mz[nx][ny] == '_') {
						if (c > 0 && dp[nx][ny][c] > dp[x][y][c]+1+t) {
							dp[nx][ny][c] = dp[x][y][c]+1+t;
							pq.push(make_pair(dp[nx][ny][c], make_pair(nx*m+ny, c)));
						}
					} else {
						int c2 = c;
						if (mz[nx][ny] == 'C') c2 = 1;
						if (dp[nx][ny][c2] > dp[x][y][c] + 1) {
							dp[nx][ny][c2] = dp[x][y][c]+1;
							pq.push(make_pair(dp[nx][ny][c2], make_pair(nx*m+ny, c2)));
						}
					}
				}
			}
		}
		return -1;
	}
};
