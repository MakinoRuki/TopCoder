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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
ll dp[N][N][2][6];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
class Never3Steps {
public:
	int count(int x, int y) {
		memset(dp, 0LL, sizeof(dp));
		if (x == 0 && y == 0) {
			return 1LL;
		}
		dp[0][1][0][1] = 1LL;
		dp[1][0][1][1] = 1LL;
		for (int i = 0; i <= x; ++i) {
			for (int j = 0; j <= y; ++j) {
				for (int s = 0; s < 2; ++s) {
					for (int t = 1; t < 5; ++t) {
						if (dp[i][j][s][t] > 0) {
						    if (i+dx[s]<=x && j + dy[s]<=y) dp[i+dx[s]][j+dy[s]][s][min(4,t+1)] = (dp[i+dx[s]][j+dy[s]][s][min(4,t+1)] + dp[i][j][s][t]) % mod;
							if (t != 3 && i+dx[!s]<=x && j+dy[!s]<=y) dp[i+dx[!s]][j+dy[!s]][!s][1] = (dp[i+dx[!s]][j+dy[!s]][!s][1] + dp[i][j][s][t]) % mod;
						}
					}
				}
			}
		}
		ll ans = 0LL;
		for (int s = 0; s < 2; ++s) {
			for (int t = 1; t < 5; ++t) {
				if (t != 3) ans = (ans + dp[x][y][s][t]) % mod;
			}
		}
		return ans;
	}
};
