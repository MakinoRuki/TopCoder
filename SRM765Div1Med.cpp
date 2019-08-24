// Tag : DP

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
ll dp[2][200001][2][2];
class NiceMultiples {
	public:
		ll ans;
		vector<int> bits;
		int count(ll m, ll u, ll b) {
			ans = 0LL;
			if (m > 200000) {
				for (ll i = 1; i <= u / m; ++i) {
					ll x = i * m;
					while(x) {
						if (x % b == 0) break;
						x /= b;
					}
					if (!x) ans = (ans+1)%mod;
				} 
			} else {
				memset(dp, 0, sizeof(dp));
				bits.clear();
				ll x = u;
				while(x) {
					bits.push_back(x % b);
					x /= b;
				}
				reverse(bits.begin(), bits.end());
				dp[0][0][0][1] = 1;
				for (int i = 0; i < bits.size(); ++i) {
					int now = i & 1;
					memset(dp[now ^ 1], 0, sizeof(dp[now ^ 1]));
					for (int r = 0; r < m; ++r) {
						for (int s = 0; s < 2; ++s) {
							for (int cz = 0; cz < 2; ++cz) {
								for (int x = 0; x < b; ++x) {
									if (x == 0) {
										if (!cz) continue;
									}
									if (x > bits[i]) {
										if (!s) continue;
									}
									dp[now ^ 1][(r*b + x) % m][s || (x < bits[i])][cz && (!x)] = (dp[now ^ 1][(r*b + x) % m][s || (x < bits[i])][cz && (!x)] + dp[now][r][s][cz]) % mod;
								}
							}
						}
					}
				}
				int bs = bits.size();
				ans = (dp[bs & 1][0][0][0] + dp[bs & 1][0][1][0]) % mod;
			}
			return ans;
		}
};
