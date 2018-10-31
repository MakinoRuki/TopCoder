#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
class DigitStringDiv1 {
	public:
		int n;
		ll dp[N][N][2][3];
		ll count(string s, int x) {
			n = s.size();
			memset(dp, 0, sizeof(dp));
			int y = x;
			vector<int> ds;
			ds.clear();
			while(y) {
				ds.push_back(y % 10);
				y /= 10;
			}
			int m = ds.size();
			if (n < m) return 0;
			while(ds.size() < n) ds.push_back(0);
			reverse(ds.begin(), ds.end());
			dp[n][0][1][0] = 1;
			for (int i = n; i > 0; --i) {
				for (int j = 0; j <= n - i; ++j) {
					ll pre0 = dp[i][j][0][0] + dp[i][j][1][0];
					ll pre1 = dp[i][j][0][1] + dp[i][j][1][1];
					ll pre2 = dp[i][j][0][2] + dp[i][j][1][2];
					if (s[i - 1] - '0' == ds[n - 1 - j]) {
						dp[i - 1][j + 1][s[i-1]=='0'][0] += pre0;
						dp[i - 1][j + 1][s[i-1]=='0'][1] += pre1;
						dp[i - 1][j + 1][s[i-1]=='0'][2] += pre2;
					} else if (s[i - 1] - '0' < ds[n - 1 - j]) {
						dp[i - 1][j + 1][s[i-1]=='0'][1] += pre0+pre1+pre2;
					} else {
						dp[i - 1][j + 1][s[i-1]=='0'][2] += pre0+pre1+pre2;
					}
					for (int z = 0; z < 2; ++z) {
						for (int k = 0; k < 3; ++k) {
							dp[i - 1][j][z][k] += dp[i][j][z][k];
						}
					}
				}
			}
			ll ans = 0LL;
			for (int i = m; i <= n; ++i) {
				ans += dp[0][i][0][2];
			}
			return ans;
		}
};
