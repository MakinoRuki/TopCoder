#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 4005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class SumOverPermutations {
	public:
		ll dp[N];
		ll comb[N][N];
		int findSum (int n) {
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			dp[0] = 0;
			dp[1] = n;
			for (int i = 2; i <= n; ++i) {
				dp[i] = (dp[i - 1] * (ll)(n - 1) % mod) * 2LL % mod;
				for (int j = 1; j <= i - 2; ++j) {
					dp[i] = (dp[i] + dp[j] * dp[i - 1 - j] % mod * (ll)(n - 2) % mod * comb[i - 1][j] % mod) % mod;
				}
			}
			return (int)dp[n];
		}
};
