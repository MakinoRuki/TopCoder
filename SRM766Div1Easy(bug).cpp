#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[1201][601][22][2];
class HockeyPlayoff {
	public:
		int m;
		ll getpw(ll a, ll b) {
			ll res = 1;
			while(b) {
				if (b&1) res = res*a % mod;
				a = a * a %mod;
				b/=2;
			}
			return res;
		}
		int winProbability(int wn, int aw, int bw) {
			m = wn + wn - 1;
			memset(dp, 0, sizeof(dp));
			ll pw = getpw(100, m-1);
			dp[1][1][1][0] = aw * pw % mod;
			dp[1][0][1][1] = bw * pw % mod;
			ll ans = 0LL;
			if (wn == 1) {
				ans = dp[1][wn][1][0];
			}
			for (int i = 1; i <= m; ++i) {
				int ni = i / 2;
				int p = aw;
				if (ni % 2) p = bw;
				for (int j = 0; j < wn; ++j) {
					for (int k = 0; p + 5 * k <= 100; ++k) {
						int p2 = p;
						if (k >= 2) p2 = min(100, p2 + 5 * k);
						int nk = p + 5 * k < 100 ? k + 1 : k;
						dp[i+1][j+1][nk][0] = (dp[i+1][j+1][nk][0] + dp[i][j][k][0] * (ll)p2 % mod * pw % mod) % mod;
						dp[i+1][j][1][1] = (dp[i+1][j][1][1] + dp[i][j][k][0] * (ll)max(0, 100-p2) % mod * pw % mod) % mod;
						p2 = 100-p;
						if (k >= 2) p2 = min(100, p2 + 5 * k);
						dp[i+1][j+1][1][0] = (dp[i+1][j+1][1][0] + dp[i][j][k][1] * (ll)max(0, 100-p2) % mod * pw % mod) % mod;
						dp[i+1][j][nk][1] = (dp[i+1][j][nk][1] + dp[i][j][k][1] * (ll)p2 % mod * pw % mod) % mod;
					}
				}
			}
			for (int i = 1; i <= m; ++i) {
				for (int k = 0; k <= 20; ++k) {
					for (int t = 0; t < 2; ++t) {
						ans = (ans + dp[i][wn][k][t]) % mod;
					}
				}
			}
			return ans;
		}
};
