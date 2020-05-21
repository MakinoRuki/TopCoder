#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class NoRepeatPlaylist {
	public:
		ll dp[N][N];
		int numPlaylists(int n, int m, int p) {
			memset(dp, 0LL, sizeof(dp));
			dp[0][0] = 1LL;
			for (int i = 0; i < p; ++i) {
				for (int j = 0; j <= i; ++j) {
					if (dp[i][j] > 0) {
						if (j+1<=n) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j] * (ll)(n-j) % mod) % mod;
						if (j >= m) {
							dp[i+1][j] = (dp[i+1][j] + dp[i][j] * (ll)(j - m) % mod) % mod;
						}
					}
				}
			}
			return dp[p][n];
		}
};
