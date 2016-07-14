#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class SuccessfulMerger {
	public:
		int n;
		vector<int> edges[N];
		bool onCircle[N];
		int deg[N];
		bool vis[N];
		bool check (vector<int> & road, int tar) {
			memset(vis, false, sizeof(vis));
			int cur = road[tar];
			while (!vis[cur] && cur != tar) {
				vis[cur] = true;
				cur = road[cur];
			}
			return cur == tar;
		}
		int minimumMergers (vector<int> road) {
			n = road.size();
			memset(deg, 0, sizeof(deg));
			for (int i = 0; i < n; ++i) {
				edges[i].push_back(road[i]);
				edges[road[i]].push_back(i);
				deg[i]++;
				deg[road[i]]++;
			}
			memset(onCircle, false, sizeof(onCircle));
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				onCircle[i] = check(road, i);
				if (deg[i] > 1) ans++;
			}
			bool all = true;
			for (int i = 0; i < n; ++i) {
				if (onCircle[i] && deg[i] == 2) all = false;
			}
			if (all) ans--;
			else ans -= 2;
			return ans;
		}
};
