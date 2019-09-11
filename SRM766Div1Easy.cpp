#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[2][1201][22][2];
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
			a = res;
			res = 1LL;
			b = mod-2;
			while(b) {
				if (b&1) res = res*a%mod;
				a=a*a%mod;
				b/=2;
			}
			return res;
		}
		int getp(int tot, int k, int t, int aw, int bw) {
			int p = (tot % 4 < 2 ? aw : 100 - bw);
			if (t == 0) p += k * 5;
			else p -= k * 5;
			return min(100, max(0, p));
		}
		int winProbability(int wn, int aw, int bw) {
			m = wn + wn - 1;
			memset(dp, 0, sizeof(dp));
		//	ll pw = getpw(100, m);
			dp[1][1][1][0] = aw % mod;
			dp[1][0][1][1] = (100-aw) % mod;
		//    dp[0][0][0][0] = 1;
			ll ans = 0LL;
			for (int i = 1; i <= m; ++i) {
				int now = i&1;
				memset(dp[now^1], 0, sizeof(dp[now^1]));
				for (int j = 0; j <= i; ++j) {
					for (int k = 0; k <= 20; ++k) {
						for (int t = 0; t < 2; ++t) {
							int p1 = getp(i, k, t, aw, bw);
							int p2 = 100 - p1;
							int nk = (k+1<=20 ? k + 1: 20);
							dp[now^1][j+1][(t == 0 ? nk : 1)][0] = (dp[now^1][j+1][(t == 0 ? nk : 1)][0] + dp[now][j][k][t] * (ll)p1 % mod) % mod;
							dp[now^1][j][(t == 1?nk:1)][1] = (dp[now^1][j][(t==1?nk:1)][1] + dp[now][j][k][t]*(ll)p2 % mod) % mod;
						}
					}
				}
			}
			for (int i = wn; i <= m; ++i) {
				for (int j = 0; j <= 20; ++j) {
					for (int k = 0; k < 2; ++k) {
						ans = (ans + dp[m&1][i][j][k]) % mod;
					}
				}
			}
		//	ans = ans * pw % mod;
			return ans;
		}
};
