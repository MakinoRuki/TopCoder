#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class AlienAndSetDiv1 {
	public:
		int dp[N][N][1<<10];
		void update(int & val, int add) {
			val = (val + add) % mod;
		}
		int getNumber (int n, int k) {
			k--;
			memset(dp, 0LL, sizeof(dp));
			dp[0][0][0] = 1;
			int ans = 0;
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					for (int s = 0; s < (1<<k); ++s) {
						if (dp[i][j][s] == 0) continue;
						if (i == n && j == n) {
							ans = (ans + dp[i][j][s]) % mod;
							continue;
						}
						int cnt1 = __builtin_popcount(s);
						int cnt2 = min(i + j, k) - cnt1;
					//	int cnt2 = k-cnt1;
						if (i >= j || (j - i) > cnt2) {
							update(dp[i+1][j][((s<<1)+1)&((1<<k)-1)], dp[i][j][s]);
						}
						if (j >= i || (i - j) > cnt1) {
							update(dp[i][j+1][(s<<1)&((1<<k)-1)], dp[i][j][s]);
						}
					}
				}
			}
			return ans;
		}
};
