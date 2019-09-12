// TAG : search
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class BannedBook {
	public:
		bool vis[N];
		int n;
		vector<int> ans;
		vector<string> frs;
		void dfs(int u, bool flag) {
			vis[u] = true;
			if (flag) {
				ans.push_back(u);
			}
			for (int i = 0; i < n; ++i) {
				if (frs[u][i] == 'Y' && !vis[i]) {
					dfs(i, !flag);
				}
			}
			if (!flag) {
				ans.push_back(u);
			}
		}
		vector<int> passAround(vector<string> fr) {
			frs = fr;
			n = frs.size();
			ans.clear();
			memset(vis, false, sizeof(vis));
			for (int i = 0; i < n; ++i) {
				if (!vis[i]) dfs(i, true);
			}
			return ans;
		}
};
