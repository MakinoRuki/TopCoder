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
#define N 105
#define M 10005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
ll dp[2][M][N];
class FeedADrake {
public:
	int n;
	int feed(int st, vector<int> cs, int es) {
		n = (int)cs.size();
		sort(cs.begin(), cs.end());
		memset(dp, -1, sizeof(dp));
		dp[0][0][0] = 0;
		for (int i = 0; i < n; ++i) {
			int now = i&1;
			for (int j = 0; j <= st; ++j) {
				for (int k = 0; k <= es; ++k) {
					dp[now^1][j][k] = -1;
				}
			}
			for (int j = 0; j <= st; ++j) {
				for (int k = 0; k <= es; ++k) {
					if (dp[now][j][k] >= 0) {
						ll dt = cs[i];
						dp[now^1][j][k] = max(dp[now^1][j][k], dp[now][j][k]);
						if (j + dt <= st || j < st) {
							dp[now^1][min(j+dt,(ll)st)][k] = max(dp[now^1][min(j+dt,(ll)st)][k], dp[now][j][k]+dt);
						} else {
							if (k+1 <= es) {
								dp[now^1][j][k+1] = max(dp[now^1][j][k+1], dp[now][j][k]+dt);
							}
						}
					}
				}
			}
		}
		ll ans = 0LL;
		for (int i = 0; i <= st; ++i) {
			for (int k = 0; k <= es; ++k) {
				ans = max(ans, dp[n&1][i][k]);
			}
		}
		return ans;
	}
};
