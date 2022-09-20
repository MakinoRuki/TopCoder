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
#define M 200015
#define N 110
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
//bool vis[N][N][N*N];
int dp[N][M];
int dp2[N][M];
class FlippingCoinSum {
public:
	int n;
	vector<int> flip(vector<int> us, vector<int> ds, int gg) {
		int n1 = (int)us.size();
		//int n2 = (int)ds.size();
		for (int i = 0; i < ds.size(); ++i) {
			us.push_back(ds[i]);
		}
		n = (int)us.size();
		int tot=0;
		for (int i = 0; i < n; ++i) {
			tot += us[i];
		}
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= tot + gg; ++j) {
				dp[i][j] = inf;
				dp2[i][j] = -1;
			}
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= tot + gg; ++j) {
				if (dp[i][j] < inf) {
					if (i + 1 <= n1) {
						if (j + us[i] <= tot+gg && dp[i][j] < dp[i+1][j+us[i]]) {
							dp[i+1][j+us[i]] = dp[i][j];
							dp2[i+1][j+us[i]] = 0;
						}
						if (dp[i][j]+1 < dp[i+1][j]) {
							dp[i+1][j] = dp[i][j]+1;
							dp2[i+1][j] = 1;
						}
					} else {
						if (dp[i][j] < dp[i+1][j]) {
							dp[i+1][j] = dp[i][j];
							dp2[i+1][j] = 0;
						}
						if (j + us[i] <= tot+gg && dp[i][j]+1 < dp[i+1][j+us[i]]) {
							dp[i+1][j+us[i]] = dp[i][j]+1;
							dp2[i+1][j+us[i]] = 1;
						}
					}
				}
			}
		}
		//cout<<dp[n][gg]<<" "<<dp2[n][gg]<<endl;
		if (dp[n][gg] >= inf) {
			return {-123456789};
		}
		int cur = gg;
		vector<int> ans;
		ans.clear();
		for (int i = n; i >= 1; --i) {
			if (dp2[i][cur]) {
				if (i > n1) {
					ans.push_back(us[i-1]);
					cur -= us[i-1];
				} else {
					ans.push_back(-us[i-1]);
				}
			} else {
				if (i <= n1) {
					cur -= us[i-1];
				}
			}
		}
		return ans;
	}
};
