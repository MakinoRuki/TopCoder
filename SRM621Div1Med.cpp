#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 4002
using namespace std;
typedef long long ll;
class TreesAnalysis {
	public:
		int n;
		bool sa[N];
		vector<int> edges1[N];
		vector<int> edges2[N];
		ll ans;
		int res[N];
		int totu;
		int dfs1(int u, int p) {
			sa[u] = true;
			int sn = 1;
			for (int i = 0; i < edges1[u].size(); ++i) {
				int v = edges1[u][i];
				if (v == p) continue;
				sn += dfs1(v, u);
			}
			return sn;
		}
		int dfs2(int u, int p) {
			int tot = 1;
			res[u] = (sa[u] ? 1 : 0);
			for (int i = 0; i < edges2[u].size(); ++i) {
				int v = edges2[u][i];
				if (v == p) continue;
				int sv = dfs2(v, u);
				tot += sv;
				int v1 = res[v];
				res[u] += res[v];
				int v2 = totu - v1;
				int v3 = sv - v1;
				int v4 = n - (totu + sv - v1);
				int mv = max(max(v1, v2), max(v3, v4));
				ans += (ll)mv * (ll)mv;
			}
			return tot;
		}
		ll treeSimilarity(vector <int> tree1, vector <int> tree2) {
			n = tree1.size() + 1;
			for (int i = 0; i < tree1.size(); ++i) {
				edges1[tree1[i]].push_back(i);
				edges1[i].push_back(tree1[i]);
				edges2[tree2[i]].push_back(i);
				edges2[i].push_back(tree2[i]);
			}
			ans = 0LL;
			for (int u = 0; u < tree1.size(); ++u) {
				int v = tree1[u];
				memset(sa, false, sizeof(sa));
				memset(res, 0, sizeof(res));
				totu = dfs1(u, v);
				dfs2(0, -1);
			}
			return ans;
		}
};
