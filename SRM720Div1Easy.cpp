#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 202
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class SumProduct {
	public:
		ll pw10[N];
		ll comb[N][N];
		ll dp[10][10][11][N];
		ll getpw (ll a, ll m) {
			ll res = 1LL;
			ll p = m - 2;
			while (p) {
				if (p & 1) res = res * a % m;
				a = a * a % m;
				p /= 2;
			}
			return res;
		}
		int findSum (vector<int> amount, int blk1, int blk2) {
			memset(pw10, 0LL, sizeof(pw10));
			memset(comb, 0LL, sizeof(comb));
			for (int i = 0; i <= blk1 + blk2; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			pw10[0] = 1LL;
			for (int i = 1; i <= max(blk1, blk2); ++i) {
				pw10[i] = pw10[i - 1] * 10LL % mod;
			}
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < 10; ++j) {
					if (i == j && amount[i] < 2) continue;
					if (i != j && (amount[i] < 1 || amount[j] < 1)) continue;
					amount[i]--;
					amount[j]--;
					memset(dp[i][j], 0LL, sizeof(dp[i][j]));
					dp[i][j][0][0] = 1LL;
					for (int k = 0; k < 10; ++k) {
						for (int t = blk1 + blk2 - 2; t >= 0; --t) {
							for (int t1 = 0; t1 <= amount[k]; ++t1) {
								if (t + t1 <= blk1 + blk2) {
									dp[i][j][k + 1][t + t1] = (dp[i][j][k + 1][t + t1] + dp[i][j][k][t] * comb[blk1 + blk2 - 2 - t][t1] % mod) % mod;
							//		if (i == 0 && j == 1 && dp[0][1][2][3]) cout<<k<<" "<<t<<" "<<t1<<endl;
								}
							}
						}
					}
					amount[i]++;
					amount[j]++;
				}
			}
		//	cout<<dp[0][0][10][1]<<" "<<dp[0][1][10][1]<<" "<<dp[1][0][10][1]<<" "<<dp[1][1][10][1]<<endl;
			ll ans = 0LL;
			for (int i = 0; i < blk1; ++i) {
				for (int n1 = 0; n1 < 10; ++n1) {
					for (int j = 0; j < blk2; ++j) {
						for (int n2 = 0; n2 < 10; ++n2) {
							if (n1 == n2 && amount[n1] < 2) continue;
							if (n1 != n2 && (amount[n1] < 1 || amount[n2] < 1)) continue;
							ll res = ((ll)n1 * pw10[i] % mod) * ((ll)n2 * pw10[j] % mod) % mod;
							res = res * dp[n1][n2][10][blk1 + blk2 - 2] % mod;
							ll tot = (ll)(blk1 + blk2);
							tot = tot * (tot - 1);
							if (n1 == n2) tot /= 2;
							//res = res * getpw(tot, mod) % mod;
							ans = (ans + res) % mod;
						}
					}
				}
			}
			return ans;
		}
};
