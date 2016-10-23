#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SZ 205
using namespace std;
typedef long long ll;
ll mod;
class BearPermutations {
	public:
		ll dp[SZ][SZ][SZ];
		ll comb[SZ][SZ];
		void update (ll & target, ll value) {
			target = (target + value) % mod;
		}
		int countPermutations (int N, int S, int MOD) {
			mod = MOD;
			memset(comb, 0LL, sizeof(comb));
			for (int i = 0; i <= N; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
				}
			}
			memset(dp, 0, sizeof(dp));
			dp[1][0][1] = 1LL;
			for (int i = 2; i <= N; ++i) {
				for (int j = 1; j <= i; ++j) {
					if (j == 1 || j == i) {
						for (int k = 0; k <= S; ++k) {
							for (int r = 1; r <= i - 1; ++r) {
								update(dp[i][k][j], dp[i - 1][k][r]);
							}
						}
					} else {
						ll lp[SZ], rp[SZ];
						memset(lp, 0, sizeof(lp));
						memset(rp, 0, sizeof(rp));
						for (int l = 1; l < j; ++l) {
							for (int k1 = 0; k1 <= S; ++k1) {
								update(lp[j - l + k1], dp[j - 1][k1][l]);
							}
						}
						for (int r = j + 1; r <= i; ++r) {
							for (int k2 = 0; k2 <= S; ++k2) {
								update(rp[r - j + k2], dp[i - j][k2][r - j]);
							}
						}
						for (int k1 = 0; k1 <= S; ++k1) {
							for (int k2 = 0; k2 + k1<= S; ++k2) {
								ll tmp = (lp[k1] * rp[k2] % mod) * comb[i - 1][j - 1] % mod;
								update(dp[i][k1 + k2][j], tmp);
								//update(dp[i][k1 + k2][j], lp[k1] * rp[k2] % mod);
							}
						}
					}
				}
			}
			ll ans = 0LL;
			for (int k = 0; k <= S; ++k) {
				for (int j = 1; j <= N; ++j) {
					update(ans, dp[N][k][j]);
				}
			}
			return (int)ans;
		}
};
