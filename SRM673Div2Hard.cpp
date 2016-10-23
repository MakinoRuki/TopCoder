#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 105
using namespace std;
typedef long long ll;
class BearPermutations2 {
	public:
		ll dp[N];
		ll comb[N][N];
		ll fac[N];
		void update (ll & target, ll value, ll mod) {
			target = (target + value) % mod;
		}
		int getSum (int n, ll mod) {
			memset(comb, 0, sizeof(comb));
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
				}
			}
			fac[0] = 1;
			for (int i = 1; i <= n; ++i) {
				fac[i] = fac[i - 1] * (ll)i % mod;
			}
			memset(dp, 0, sizeof(dp));
			for (int i = 2; i <= n; ++i) {
				for (int j = 1; j <= i; ++j) {
					if (j == 1 || j == i) {
						update(dp[i], dp[i - 1], mod);
					} else {
						for (int k1 = 1; k1 < j; ++k1) {
							for (int k2 = j + 1; k2 <= i; ++k2) {
								ll add = ((ll)(k2 - k1) * comb[i - 1][j - 1] % mod) * (fac[j - 2] * fac[i - j - 1] % mod) % mod;
								update(dp[i], add, mod);
							}
						}
						ll add2 = (dp[j - 1] * fac[i - j] % mod + dp[i - j] * fac[j - 1] % mod) % mod * comb[i - 1][j - 1] % mod;
						update(dp[i], add2 , mod);
					}
				}
			}
			return (int)dp[n];
		}
};
