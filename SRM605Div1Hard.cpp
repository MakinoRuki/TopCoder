#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 202
using namespace std;
typedef long long ll;
ll dp[N][N][N][2];
const ll mod = 1000000007LL;
class AlienAndPermutation {
	public:
		int n;
		bool can[N][N];
		int dfs(int i, int j, int K, int c) {
			if (dp[i][j][K][c] >= 0) return dp[i][j][K][c];
			if (j >= n) return 1;
			else if (i >= n) return 0;
			dp[i][j][K][c] = 0;
			ll res = dfs(i + 1, j, K, 0);
			if (can[i][j]) {
				if (i != j && !c) {
					if (K > 0) {
						res = (res + dfs(i, j + 1, K - 1, 1)) % mod;
					}
				} else {
					res = (res + dfs(i, j + 1, K, c)) % mod;
				}
			}
			return dp[i][j][K][c] = (int)res;
		}
		int getNumber(vector<int> P, int K) {
			n = P.size();
			memset(dp, -1, sizeof(dp));
			memset(can, false, sizeof(can));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					can[i][j] = true;
					for (int k = min(i, j); k <= max(i, j); ++k) {
						can[i][j] &= (P[k] <= P[i]);
					}
				}
			}
			return dfs(0, 0, K, 0);
		}
};
