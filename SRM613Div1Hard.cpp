#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class TaroCheckers {
	public:
		ll dp[202][55][55];
		int n;
		ll comb[202][202];
		ll fac[202];
		int actLeft[202];
		int startRight[202];
		int endLeft[202];
		int free[202];
		void update(int i, int j, int k, int nj, int nk, ll x) {
			if (nj >= endLeft[i + 1]) {
				ll res = comb[nj][endLeft[i+1]] * fac[endLeft[i + 1]] % mod;
				res = res * x % mod;
				dp[i + 1][nj - endLeft[i+1]][nk] = (dp[i+1][nj-endLeft[i+1]][nk] + dp[i][j][k] * res % mod) % mod;
			}
		}
		int getNumber(vector<int> left, vector<int> right, int m) {
			n = left.size();
			for (int i = 0; i <= 200; ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
				}
				if (i == 0) fac[i] = 1LL;
				else fac[i] = fac[i-1]*(ll)i%mod;
			}
			for (int j = 1; j <= m; ++j) {
				for (int i = 0; i < n; ++i) {
					if (left[i] >= j) actLeft[j]++;
				}
			}
			for (int i = 0; i < n; ++i) {
				endLeft[left[i]]++;
				startRight[m - right[i] + 1]++;
			}
			for (int j = 1; j <= m; ++j) {
				for (int i = 0; i < n; ++i) {
					if (left[i] < j && m - right[i] + 1 > j) free[j]++;
				}
			}
			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 1LL;
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j <= actLeft[i]; ++j) {
					for (int k = 0; k <= n; ++k) {
						if (dp[i][j][k] == 0) continue;
						int nk = k + startRight[i + 1];
						update(i, j, k, j, nk - 1, nk);
						if (j + 1 <= actLeft[i + 1]) {
							update(i, j, k, j + 1, nk, 1);
						}
						update(i, j, k, j, nk, 1);
						update(i, j, k, j, nk, free[i + 1]);
					}
				}
			}
			return dp[m][0][0];
		}
};
