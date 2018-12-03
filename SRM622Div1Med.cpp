#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class Ethernet {
	public:
		vector<pii> edges[N];
		int n;
		int vmaxd[N];
		int dfs (int cur, int maxd) {
			int res = 0;
			vector<int> ds;
			ds.clear();
			for (int i = 0; i < edges[cur].size(); ++i) {
				int v = edges[cur][i].first;
				int d = edges[cur][i].second;
				res += dfs(v, maxd);
				ds.push_back(d + vmaxd[v]);
			}
			sort(ds.begin(), ds.end());
			int i = ds.size() - 1;
			for (; i >= 0; --i) {
				if (ds[i] > maxd) res++;
				else break;
			}
			for (; i >= 1; --i) {
				if (ds[i] + ds[i - 1] > maxd) res++;
				else break;
			}
			vmaxd[cur] = (i >= 0 ? ds[i] : 0);
			return res;
		}
		int connect(vector <int> parent, vector <int> dist, int maxDist) {
			n = parent.size() + 1;
			for (int i = 0; i < parent.size(); ++i) {
				edges[parent[i]].push_back(mp(i + 1, dist[i]));
			}
			memset(vmaxd, 0, sizeof(vmaxd));
			return dfs(0, maxDist) + 1;
		}
};
