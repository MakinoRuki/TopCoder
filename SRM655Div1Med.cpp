// Two kinds of implementations.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class Nine {
	public:
		int m;
		ll dp[2][100000];
		void update (ll & target, ll value) {
			target = (target + value) % mod;
		}
		int count (int n, vector<int> d) {
			m = d.size();
			memset(dp, 0LL, sizeof(dp));
			dp[0][0] = 1LL;
			int now = 0;
			for (int i = 0; i < (1<<n); ++i) {
				memset(dp[now ^ 1], 0LL, sizeof(dp[now ^ 1]));
				int cnt = 0;
				for (int j = 0; j < m; ++j) {
					if (d[j] == i) cnt++;
				}
				ll dp1[cnt + 1][10];
				memset(dp1, 0LL, sizeof(dp1));
				dp1[0][0] = 1LL;
				for (int j = 0; j < cnt; ++j) {
					for (int k = 0; k < 9; ++k) {
						if (dp1[j][k]) {
							for (int t = 0; t <= 9; ++t) {
								update(dp1[j + 1][(k + t) % 9], dp1[j][k]);
							}
						}
					}
				}
				for (int j = 0; j <= 88888; ++j) {
					if (dp[now][j] > 0) {
						for (int k = 0; k < 9; ++k) {
							int nj = 0;
							int pw = 1;
							int tmp = j;
							for (int b = 0; b < n; ++b) {
								if ((1<<b) & i) {
									nj += (tmp%10 + k) % 9 * pw;
								} else {
									nj += tmp%10 * pw;
								}
								tmp /= 10;
								pw *= 10;
							}
							dp[now ^ 1][nj] = (dp[now ^ 1][nj] + dp[now][j] * dp1[cnt][k] % mod) % mod;
						}
					}
				}
				now ^= 1;
			}
			return dp[(1<<n) & 1][0];
		}
};




/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define SZ1 40
#define SZ2 60000
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[SZ1][SZ2];
ll tmp[SZ2][SZ1];
class Nine {
	public:
		int m;
		int num[SZ1];
		int count (int N, vector<int> d) {
			m = d.size();
			memset(num, 0, sizeof(num));
			for (int i = 0; i < m; ++i) {
				num[d[i]]++;
			}
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1LL;
			for (int i = 0; i < (1<<N); ++i) {
				memset(tmp, 0LL, sizeof(tmp));
				tmp[0][0] = 1LL;
				for (int j = 0; j < num[i]; ++j) {
					for (int k1 = 0; k1 < 9; ++k1) {
						for (int k2 = 0; k2 <= 9; ++k2) {
							tmp[j + 1][(k1 + k2) % 9] = (tmp[j + 1][(k1 + k2) % 9] + tmp[j][k1]) % mod;
						}
					}
				}
				for (int j = 0; j <= 59048; ++j) {
					for (int k1 = 0; k1 < 9; ++k1) {
						int bits[6];
						int oj = j;
						for (int b = 0; b < N; ++b) {
							bits[b] = oj % 9;
							oj /= 9;
						}
						int nj = 0;
						int pw = 1;
						for (int b = 0; b < N; ++b) {
							if (i & (1<<b)) {
								nj += ((bits[b] + k1) % 9) * pw;
							} else {
								nj += bits[b] * pw;
							}
							pw *= 9;
						}
						dp[i + 1][nj] = (dp[i + 1][nj] + dp[i][j] * tmp[num[i]][k1] % mod) % mod;
					}
				}
			}
			return dp[1<<N][0];
		}
};*/
