#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 252
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class PermutationCountsDiv2 {
	public:
		int lr[N], rr[N];
		ll dp[N][N];
		ll comb[N][N];
		bool check (int lf, int rt, int cur) {
			if (cur == lf && rr[cur]) return true;
			if (cur == rt && lr[cur]) return true;
			if (cur > lf && cur < rt && lr[cur] && rr[cur]) return true;
			return false;
		}
		int countPermutations (int n, vector<int> pos) {
			sort(pos.begin(), pos.end());
			int j = 0;
			for (int i = 0; i < n - 1; ++i) {
				if (j < pos.size() && i == pos[j] - 1) {
					rr[i] = 1;
					lr[i + 1] = 0;
					j++;
				} else {
					rr[i] = 0;
					lr[i + 1] = 1;
				}
			}
			memset(comb, 0LL, sizeof(comb));
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			memset(dp, 0LL, sizeof(dp));
			for (int i = n - 1; i >= 0; --i) {
				for (int j = 0; j < n; ++j) {
					if (i == j) dp[i][j] = 1LL;
					for (int k = i; k <= j; ++k) {
						if (check(i, j, k)) {
							if (k == i) dp[i][j] = (dp[i][j] + dp[k + 1][j]) % mod;
							if (k == j) dp[i][j] = (dp[i][j] + dp[i][k - 1]) % mod;
							dp[i][j] = (dp[i][j] + dp[i][k - 1] * dp[k + 1][j] % mod * comb[j - i][k - i] % mod) % mod;
						}
					}
				}
			}
			return dp[0][n - 1];
		}
};
