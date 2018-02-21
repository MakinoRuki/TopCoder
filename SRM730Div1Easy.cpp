#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
#define inf 1000000000
using namespace std;
class StonesOnATree {
	public:
		int n;
		bool has[N];
		vector<int> sons[N];
		vector<int> w;
		int dfs(int root) {
			if (sons[root].size() == 1) {
				int v = dfs(sons[root][0]);
				return max(v, w[sons[root][0]] + w[root]);
			}
			if (sons[root].size() == 2) {
				int v0 = dfs(sons[root][0]);
				int v1 = dfs(sons[root][1]);
				int w0 = max(v0, w[sons[root][0]] + v1);
				int w1 = max(v1, w[sons[root][1]] + v0);
				return max(min(w0, w1), w[root] + w[sons[root][0]] + w[sons[root][1]]);
			}
			return w[root];
		}
		int minStones(vector<int> p, vector<int> ww) {
			n = ww.size();
			w = ww;
			for (int i = 0; i < p.size(); ++i) {
				sons[p[i]].push_back(i + 1);
			}
			return dfs(0);
		}
};
