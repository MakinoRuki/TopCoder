#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class SubtreeSum {
	public:
		int n;
		vector<int> edges[N];
		ll tot, ans;
		ll dp[N];
		vector<int> x;
		void dfs (int cur, int par, int bit) {
			if (bit < 0 || !((1<<bit) & x[cur])) {
				dp[cur] = 1;
			}
			for (int i = 0; i < edges[cur].size(); ++i) {
				int nxt = edges[cur][i];
				if (par != nxt) {
					dfs(nxt, cur, bit);
					dp[cur] += dp[cur] * dp[nxt];
				}
			}
		}
		int getSum(vector<int> p, vector<int> _x) {
			x = _x;
			n = x.size();
			for (int i = 0; i < p.size(); ++i) {
				edges[p[i]].push_back(i + 1);
				edges[i + 1].push_back(p[i]);
			}
			tot = 0LL;
			ans = 0LL;
			memset(dp, 0, sizeof(dp));
			dfs(0, -1, -1);
			for (int i = 0; i < n; ++i) {
				tot += dp[i];
			}
			for (int i = 30; i >= 0; --i) {
				memset(dp, 0, sizeof(dp));
				dfs(0, -1, i);
				ll res = 0LL;
				for (int j = 0; j < n; ++j) {
					res += dp[j];
				}
				res = (tot - res + mod) % mod;
				ans = (ans + res * (1LL << i) % mod) % mod;
			}
			return (int)ans;
		}
};
