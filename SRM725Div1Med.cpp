#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 15
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll dp[N][1<<N];
class HiddenTree {
	public:
		vector<int> edges[N];
		int count(vector<int> b) {
			int n = b.size();
			sort(b.begin(), b.end());
			for (int i = 0; i < n; ++i) {
				for (int s = 0; s < (1<<i); ++s) {
					ll sum = 0LL;
					for (int j = 0; j < i; ++j) {
						if ((1<<j) & s) {
							sum += b[j];
						}
					}
					if (sum < b[i]) {
						edges[i].push_back(s);
					}
				}
			}
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1LL;
			for (int i = 1; i < n; ++i) {
				for (int s = 0; s < (1<<i); ++s) {
					for (int j = 0; j < edges[i].size(); ++j) {
						int t = edges[i][j];
						if ((s & t) != t) continue;
						dp[i][s] = (dp[i][s] + dp[i - 1][s ^ t]) % mod;
					}
				}
			}
			ll ans = 0LL;
			for (int i = 0; i < (1<<n); ++i) {
				ans = (ans + dp[n - 1][i]) % mod;
			}
			return ans;
		}
};
