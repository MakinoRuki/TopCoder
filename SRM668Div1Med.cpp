#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define SZ 2010
#define mp make_pair
using namespace std;
class WalkingToSchool {
	public:
		int n;
		vector<int> edges[SZ];
		bool vis[SZ];
		bool inq[SZ][SZ * 4];
		queue<pair<int, int> > que;
		void dfs (int u) {
			if (vis[u]) return ;
			vis[u] = true;
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				if (!vis[v]) dfs(v);
			}
		}
		string canWalkExactly (int N, vector<int> from, vector<int> to) {
			n = N;
			for (int i = 0; i < from.size(); ++i) {
				edges[from[i]].push_back(to[i]);
			}
			memset(vis, false, sizeof(vis));
			dfs(0);
			if (!vis[1]) return "Chores";
			memset(vis, false, sizeof(vis));
			dfs(1);
			if (!vis[0]) return "Chores";
			memset(inq, false, sizeof(inq));
			inq[0][0] = true;
			que.push(mp(0, 0));
			int gcd = 0;             //0-->1connected componets must have two cycles with gcd == 1. That is to say, all the cycles must have gcd == 1.
			while (!que.empty()) {
				if (gcd == 1) break;
				int u = que.front().first;
				int d = que.front().second;
				que.pop();
				if (u == 0 && d > 0) {                     //As long as all cycles which past 0 have gcd == 1, all the cases can be covered.
					if (gcd == 0) gcd = d;
					else gcd = __gcd(gcd, d);
				} 
					if (d >= 3 * n) continue; // We only need gcd(a+k, b+k, a+b+k)=1.
					for (int i = 0; i < edges[u].size(); ++i) {
						int v = edges[u][i];
						if (!inq[v][d + 1]) {
							inq[v][d + 1] = true;
							que.push(mp(v, d + 1));
						}
					}
			}
			return gcd == 1 ? "Freedom" : "Chores";
		}
};
