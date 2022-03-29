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
ll dp[10][40][40];
class TwoFairDice {
public:
	ll finish(vector<int> a, vector<int> b) {
		memset(dp, 0, sizeof(dp));
		int ca = 0, cb = 0;
		for (int i = 0; i < a.size(); ++i) {
			for (int j = 0; j < b.size(); ++j) {
				if (a[i] > b[j]) {
					ca++;
				}
			}
		}
		for (int i = 0; i < b.size(); ++i) {
			for (int j = 0; j < a.size(); ++j) {
				if (b[i] > a[j]) {
					cb++;
				}
			}
		}
		dp[0][ca][cb] = 1LL;
		int m = 6 - (int)b.size();
		for (int i = 0; i < m; ++i) {
			for (int j1 = 0; j1 <= 36; ++j1) {
				for (int j2 = 0; j2 <= 36; ++j2) {
					if (dp[i][j1][j2] > 0) {
						for (int x = 0; x <= 1000; ++x) {
							int da = 0, db = 0;
							for (int z = 0; z < a.size(); ++z) {
								if (a[z] > x) da++;
								else if (a[z] < x) db++;
							}
							dp[i+1][j1 + da][j2+db] = (dp[i+1][j1+da][j2+db] + dp[i][j1][j2]);
						}
					}
				}
			}
		}
		ll ans = 0LL;
		for (int i = 0; i <= 36; ++i) {
			ans = ans + dp[m][i][i];
		}
		return ans;
	}
};
