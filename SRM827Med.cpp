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
#define M 200005
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
const int MAXV = 2005;
const int INF = 1<<30;
int dp[52][14*50];
class CoinFlipping2 {
public:
	vector<int> correctHeads(vector<string> mt, int dc) {
		int n = (int)mt.size();
		int m = (int)mt[0].size();
		vector<int> ans;
		ans.clear();
		int tot=0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mt[i][j] != '.') {
					tot++;
				}
			}
		}
		for (int i = 0; i < (1<<n); ++i) {
			for (int j = 0; j <= m; ++j) {
				for (int k = 0; k <= tot; ++k) {
					dp[j][k] = -2;
				}
			}
			int cnt[52][2];
			for (int j = 0; j < m; ++j) {
				cnt[j][0] = 0;
				int num=0;
				for (int r = 0; r < n; ++r) {
					if (mt[r][j] == 'H') {
						num++;
						if ((1<<r) & i) {
							continue;
						}
						cnt[j][0]++;
					} else if (mt[r][j] == 'T') {
						num++;
						if ((1<<r) & i) {
							cnt[j][0]++;
						}
					}
				}
				cnt[j][1] = num - cnt[j][0];
			}
			dp[0][cnt[0][0]] = -1;
			dp[0][cnt[0][1]] = 0;
			for (int j = 0; j < m-1; ++j) {
				for (int k = 0; k <= tot; ++k) {
					if (dp[j][k] > -2) {
						dp[j+1][k + cnt[j+1][0]] = dp[j][k];
						dp[j+1][k + cnt[j+1][1]] = j+1;
					}
				}
			}
			if (dp[m-1][dc] > -2) {
				int cc = dp[m-1][dc];
				int sum = dc;
				for (int j = m-1; j >= 0; --j) {
					if (cc == j) {
						ans.push_back(j + n);
						sum -= cnt[j][1];
						if (j > 0) cc = dp[j-1][sum];
					} else {
						sum -= cnt[j][0];
					}
				}
				for (int r = 0; r < n; ++r) {
					if ((1<<r) & i) {
						ans.push_back(r);
					}
				}
				return ans;
			}
		}
		return {-1};
	}
};
