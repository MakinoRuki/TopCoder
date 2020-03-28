#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <deque>
#define N 1002
using namespace std;
class RankingStudents {
	public:
	//	int val[N];
	//	int vis[N];
		int deg[N];
		int deg2[N];
		int late[N];
		bool vis[N];
		vector<int> edges[N];
	//	bool dfs(int u) {
		//	if (vis[u] < 0) return false;
		// 	vis[u] = -1;
		// 	for (int i = 0; i < edges[u].size(); ++i) {
		// 		if (!dfs(edges[u][i])) return false;
		// 	}
		// 	vis[u] = 1;
		// 	return true;
		// }
		int dfs(int u) {
			if (vis[u]) return late[u];
			for (int i = 0; i < edges[u].size(); ++i) {
				late[u] = min(dfs(edges[u][i])-1, late[u]);
			}
			vis[u] = true;
			return late[u];
		}
		string rankingPossible(int n, vector<int> f, vector<int> a, vector<int> b) {
		//	memset(val, 0, sizeof(val));
			memset(deg,0,sizeof(deg));
			memset(deg2,0,sizeof(deg2));
			memset(vis, false, sizeof(vis));
			int m = a.size();
		//	memset(vis, 0, sizeof(vis));
			for (int i = 0;i < m; ++i) {
				edges[a[i]].push_back(b[i]);
				deg[b[i]]++;
				deg2[b[i]]++;
			}
		//	for (int i = 0;  i < n; ++i) {
			//	if (deg[i]) continue;
			//	memset(vis, 0, sizeof(vis));
				//if (!dfs(i)) return "Impossible";
		//	}
			int tot=0;
			set<int> ss2;
			ss2.clear();
			for (int i = 0; i < n; ++i) {
				if (deg2[i]==0) ss2.insert(i);
			}
			while(tot<n) {
				if (ss2.empty()) return "Impossible";
				int u = *ss2.begin();
				ss2.erase(u);
				tot++;
				for (int i = 0; i < edges[u].size(); ++i) {
					int v = edges[u][i];
					deg2[v]--;
					if (deg2[v]==0 && ss2.find(v)==ss2.end()) {
						ss2.insert(v);
					}
				}
			}
			for (int i = 0; i < n; ++i) late[i] = f[i];
			for (int i = 0; i < n; ++i) {
				if (!vis[i] && dfs(i)<0) return "Impossible";
			}
			vector<int> ans;
			set<pair<int,int>> ss;
			ss.clear();
			for (int i = 0; i < n; ++i) {
				if (deg[i]==0) ss.insert(make_pair(late[i], i));
			}
			while(ans.size()<n) {
				if (ss.empty()) return "Impossible";
				auto p =*ss.begin();
				int u = p.second;
				ss.erase(p);
				ans.push_back(u);
				if (ans.size()-1 > late[u]) return "Impossible";
				for (int i = 0; i < edges[u].size(); ++i) {
					int v = edges[u][i];
					deg[v]--;
					if (deg[v]==0 && ss.find(make_pair(late[v],v))==ss.end()) {
						ss.insert(make_pair(late[v], v));
					}
				}
			}
			return "Possible";
		}
};
