#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define N 52
#define inf 1000000000
#define mp make_pair
#define pii pair<int, int>
using namespace std;
class AllGraphCuts {
	public:
		int n;
		vector<pair<int, pii> > rank;
		vector<int> edges[N];
		int par[N];
		vector<int> ans;
		bool vis[N];
		int dis[N];
		queue<int> Q;
		int find (int u) {
			return par[u] == u ? par[u] : (par[u] = find(par[u]));
		}
		vector<int> findGraph(vector<int> x) {
			n = (int)sqrt(x.size());
			rank.clear();
			ans.clear();
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j && x[i * n + j] != 0) return {-1};
					if (x[i * n + j] != x[j * n + i]) return {-1};
					rank.push_back(mp(x[i * n + j], mp(i, j)));
				}
			}
			sort(rank.begin(), rank.end());
			for (int i = 0; i < n; ++i) {
				par[i] = i;
			}
			for (int i = rank.size() - 1; i >= 0; --i) {
				int u = rank[i].second.first;
				int v = rank[i].second.second;
				int pu = find(par[u]);
				int pv = find(par[v]);
				if (pu != pv) {
					par[pu] = pv;
					edges[u].push_back(v);
					edges[v].push_back(u);
				}
			}
/*			for (int i = 0; i < n; ++i) {
				cout<<i<<" "<<edges[i].size()<<endl;
				for (int j = 0; j < edges[i].size(); ++j) {
					cout<<edges[i][j]<<" ";
				}
				cout<<endl;
			}  */
			for (int i = 0; i < n; ++i) {
				memset(vis, false, sizeof(vis));
				for (int j = 0; j < n; ++j) {
					dis[j] = inf;
				}
				vis[i] = true;
				Q.push(i);
				while (!Q.empty()) {
					int cur = Q.front();
					Q.pop();
					for (int j = 0; j < edges[cur].size(); ++j) {
						int nxt = edges[cur][j];						
						if (!vis[nxt]) {
							dis[nxt] = min(dis[nxt], min(dis[cur], x[cur * n + nxt]));
							vis[nxt] = true;
							Q.push(nxt);
						}
					}
				}
				for (int j = 0; j < n; ++j) {
					//cout<<i<<" "<<j<<" "<<dis[j]<<endl;
					if (i != j && dis[j] != x[i * n + j]) return {-1};
				} 
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < edges[i].size(); ++j) {
					if (edges[i][j] > i) {
						int v = edges[i][j];
						ans.push_back(n * n * x[i * n + v] + n * i + v);
					}
				}
			}
			return ans;
		}
};
