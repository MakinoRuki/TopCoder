#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
class KthStringAgain {
	public:
		int n;
		ll dp[N][N];
		ll calc (string s, string p) {
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1LL;
			// 正向dp。dp[0][0]的值容易确定,而不依赖于后面的状态。
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= i; ++j) {
					int l = j;
					int r = j + n - 1 - i;
					if (l >= p.size() || s[i] == p[l]) {
						dp[i + 1][j + 1] += dp[i][j];
					}
					if (r >= p.size() || s[i] == p[r]) {
						dp[i + 1][j] += dp[i][j];
					}
				}
			}
			ll ans = 0LL;
			for (int i = 0; i <= n; ++i) {
				ans += dp[n][i];
			}
			return ans;
		}
		string getKth (string s, ll k) {
			string ans = "";
			n = s.size();
			for (int i = 0; i < n; ++i) {
				string tmp = ans + " ";
				for (char j = 'a'; j <= 'z'; ++j) {
					tmp[tmp.size() - 1] = j;
					ll cnt = calc(s, tmp);
					if (cnt < k) {
						k -= cnt;
					} else {
						ans = tmp;
						break;
					}
				}
			} 
			return ans;
		}
};
