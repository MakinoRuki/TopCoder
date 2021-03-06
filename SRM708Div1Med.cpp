#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 3002
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class PalindromicSubseq {
	public:
		int n;
		ll dp_in[N][N], dp_out[N][N];
		ll dp[N][N];
		int solve (string s) {
			n = s.size();
			memset(dp_in, 0LL, sizeof(dp_in));
			memset(dp, 0LL, sizeof(dp));
			for (int i = n; i >= 1; --i) {
				for (int j = i; j <= n; ++j) {
					if (i == j || j == i + 1) {
						if (s[i - 1] == s[j - 1]) {
							dp[i][j] = 1LL;
						}
					} else {
						if (s[i - 1] == s[j - 1]) dp[i][j] = dp_in[i + 1][j - 1] + 1LL;
					}
					dp_in[i][j] = (dp_in[i + 1][j] + dp_in[i][j - 1]) % mod;
					dp_in[i][j] = (dp_in[i][j] - dp_in[i + 1][j - 1] + mod) % mod;
					dp_in[i][j] = (dp_in[i][j] + dp[i][j]) % mod;
				}
			}
			memset(dp_out, 0LL, sizeof(dp_out));
			for (int i = 0; i <= n; ++i) {
				dp_out[0][i] = dp_out[i][n + 1] = 1LL;
			}
			for (int i = 1; i <= n; ++i) {
				for (int j = n; j >= 1; --j) {
					dp_out[i][j] = (dp_out[i][j + 1] + dp_out[i - 1][j]) % mod;
					dp_out[i][j] = (dp_out[i][j] - dp_out[i - 1][j + 1] + mod) % mod;
					if (s[i - 1] == s[j - 1]) {
						dp_out[i][j] = (dp_out[i][j] + dp_out[i - 1][j + 1]) % mod;
					}
				}
			}
			ll ans = 0LL;
			for (int i = 1; i <= n; ++i) {
				ll res = 0LL;
				for (int j = 1; j <= n; ++j) {
				//	if (i == 1) cout<<i<<" "<<j<<" "<<dp_in[i][j]<<" "<<dp_out[i][j]<<endl;
					if (j <= i) res = (res + dp[j][i] * dp_out[j - 1][i + 1] % mod) % mod;
					else res = (res + dp[i][j] * dp_out[i - 1][j + 1] % mod) % mod;
				}
			//	cout<<i<<" "<<res<<endl;
				ans ^= (res * i % mod);
			}
			return ans;
		}
};
