#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class CandidatesSelection {
	public:
		int n, m;
		bool vis[N];
		string possible (vector<string> score, vector<int> result) {
			n = score.size();
			m = score[0].size();
			vector<pii> cans;
			cans.clear();
			for (int i = 0; i < n - 1; ++i) {
				cans.push_back(mp(result[i], result[i + 1]));
			}
			memset(vis, false, sizeof(vis));
			while(true) {
				int i;
				for (i = 0; i < cans.size(); ++i) {
					if (cans[i].first > cans[i].second) break;
				}
				if (i >= cans.size()) break;
				bool ok = false;
				for (int i = 0; i < m; ++i) {
					if (vis[i]) continue;
					int j;
					for (j = 0; j < cans.size(); ++j) {
						int u = cans[j].first;
						int v = cans[j].second;
						if (score[u][i] > score[v][i]) break;
					}
					if (j < cans.size()) continue;
					ok = true;
					vis[i] = true;
					vector<pii> ncans;
					ncans.clear();
					for (j = 0; j < cans.size(); ++j) {
						int u = cans[j].first;
						int v = cans[j].second;
						if (score[u][i] == score[v][i]) ncans.push_back(cans[j]);
					}
					cans = ncans;
					break;
				}
				if (!ok) return "Impossible";
			}
			return "Possible";
		}
};
