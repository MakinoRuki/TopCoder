#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 1002
#define pii pair<int, long long>
#define mp make_pair
#define inf 1000000000000000000LL
using namespace std;
typedef long long ll;
class MaliciousPath {
	public:
		int m;
		vector<pii> edges[N];
		ll disA[N], disB[N];
		bool vis[N];
		void spfa (int s) {
			int n = s + 1;
			for (int i = 0; i < n; ++i) {
				disA[i] = inf;
			}
			memset(vis, false, sizeof(vis));
			vis[s] = true;
			disA[s] = 0LL;
			queue<int> Q;
			Q.push(s);
			while (!Q.empty()) {
				int u = Q.front();
				Q.pop();
				vis[u] = false;
				for (int i = 0; i < edges[u].size(); ++i) {
					int v = edges[u][i].first;
					ll w = edges[u][i].second;
					ll tmp = max(disB[v], disA[u] + w);
					if (tmp < disA[v]) {
						disA[v] = tmp;
						if (!vis[v]) {
							vis[v] = true;
							Q.push(v);
						}
					}
				}
			}
		}
		ll minPath (int n, int k, vector<int> from, vector<int> to, vector<int> cost) {
			m = from.size();
			for (int i = 0; i < m; ++i) {
				edges[to[i]].push_back(mp(from[i], (ll)cost[i]));
			}
			memset(disB, 0LL, sizeof(disB));
			for (int i = 0; i <= k; ++i) {
				spfa(n - 1);
				for (int j = 0; j < n; ++j) {
					for (int idx = 0; idx < edges[j].size(); ++idx) {
						int v = edges[j][idx].first;
						ll w = edges[j][idx].second;
						disB[v] = max(disB[v], disA[j] + w);
					}
				}
			}
			return disA[0] >= inf ? -1 : disA[0];
		}
};
