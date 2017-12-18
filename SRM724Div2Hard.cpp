#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class UnfinishedTournamentEasy {
	public:
		int n;
		ll dp[1<<20];
		double maximal(vector<string> G) {
			n = G.size();
			memset(dp, 0LL, sizeof(dp));
			for (int i = 0; i < (1<<n); ++i) {
				for (int x = 0; x < n; ++x) {
					if ((1<<x) & i) continue;
					int win = 0;
					for (int y = 0; y < n; ++y) {
						if (G[x][y] == 'W' || (G[x][y] == '?' && !((1<<y) & i))) {
							win++;
						}
					}
					dp[i | (1<<x)] = max(dp[i | (1<<x)], dp[i] + win * win);
				}
			}
			double ans = (double)dp[(1<<n) - 1] / (double)(n * (n - 1) * (n - 1)) - 0.25;
			return ans;
		}
};
