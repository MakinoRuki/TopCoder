#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
class HeroicScheduled2 {
	public:
		ll dp[2][1<<16];
		vector<pii> tasks;
		ll getcount(vector<int> start, vector<int> finish) {
			int n = start.size();
			int d = 0;
			for (int i = 0; i < n; ++i) {
				tasks.push_back(mp(finish[i], start[i]));
				d = max(d, finish[i]);
			}
			d++;
			sort(tasks.begin(), tasks.end());
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			for (int i = 0; i < n; ++i) {
				int now = (i + 1) & 1;
				memset(dp[now], 0, sizeof(dp[now]));
				for (int j = 0; j < (1<<d); ++j) {
					dp[now][j] += dp[now ^ 1][j];
					for (int k = tasks[i].second; k <= tasks[i].first; ++k) {
						if ((1<<k) & j) continue;
						dp[now][j | (1<<k)] += dp[now ^ 1][j];
						break;
					}
				}
			}
			ll ans = 0;
			for (int i = 0; i < (1<<d); ++i) {
				ans += dp[n & 1][i];
			}
			return ans;
		}
};
