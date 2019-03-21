#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 1002
using namespace std;
class MaxCutFree {
	public:
		int m;
		vector<int> edges[N];
		bool vis[N];
		int dp[N][2];
		int par[N];
		int dfs(int cur, int pre) {
			int res1 = 0, res2 = 0;
			for (int i = 0; i < edges[cur].size(); ++i) {
				int v = edges[cur][i];
				if (v == pre) continue;
				dfs(v, cur);
				res1 += dp[v][0];
				res2 += max(dp[v][1], dp[v][0]);
			}
			dp[cur][0] = res2;
			dp[cur][1] = res1 + 1;
			vis[cur] = true;
			return max(dp[cur][0], dp[cur][1]);
		}
		int find(int x) {
			return (x == par[x]) ? par[x] : (par[x] = find(par[x]));
		}
		int getcnt(int n, vector<int>& a, vector<int>& b, int no) {
			for (int i = 0; i < n; ++i) {
				par[i] = i;
			}
			for (int i = 0; i < m; ++i) {
				if (i == no) continue;
				int p1 = find(a[i]);
				int p2 = find(b[i]);
				if (par[p1] != p2) par[p1] = p2;
			}
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				par[i] = find(i);
				if (par[i] == i) cnt++;
			}
			return cnt;
		}
		int solve(int n, vector<int> a, vector<int> b) {
			m = a.size();
			set<int> pts;
			pts.clear();
			int cnt = getcnt(n, a, b, -1);
			for (int i = 0; i < m; ++i) {
				int cnt2 = getcnt(n, a, b, i);
				if (cnt2 > cnt) {
					edges[a[i]].push_back(b[i]);
					edges[b[i]].push_back(a[i]);
					pts.insert(a[i]);
					pts.insert(b[i]);
				}
			}
			int rem = n - pts.size();
			int ans = 0;
			memset(vis, false, sizeof(vis));
			memset(dp, -1, sizeof(dp));
			for (int i = 0; i < n; ++i) {
				if (!vis[i] && pts.find(i) != pts.end()) {
					ans += dfs(i, -1);
				}
			}
			ans += rem;
			return ans;
		}
};
