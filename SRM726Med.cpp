#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class HeroVacation {
	public:
		vector<int> ans;
		vector<int> edges[N];
		vector<int> subs[N][N];
		void dfs(int cur, int pre) {
			if (subs[pre][cur].size()) return ;
			subs[pre][cur].push_back(cur);
			for (int j = 0; j < edges[cur].size(); ++j) {
				int v = edges[cur][j];
				if (v == pre) continue;
				dfs(v, cur);
				for (int k = 0; k < subs[cur][v].size(); ++k) {
					subs[pre][cur].push_back(subs[cur][v][k]);
				}
			}
		}
		vector<int> getPermutation(vector<int> p) {
			int n = p.size();
			for (int i = 0; i < n; ++i) {
				edges[i + 1].push_back(p[i]);
				edges[p[i]].push_back(i + 1);
			}
			for (int i = 0; i < n; ++i) {
				dfs(i + 1, p[i]);
				dfs(p[i], i + 1);
			}
			n++;
			int minv = 10000, idx = -1;
			for (int i = 0; i < n; ++i) {
				int maxv = 0;
				for (int j = 0; j < edges[i].size(); ++j) {
					int v = edges[i][j];
					if (subs[i][v].size() > maxv) {
						maxv = subs[i][v].size();
					}
				}
				if (maxv <= minv) {
					minv = maxv;
					idx = i;
				}
			}
			vector<vector<int> > sons;
			sons.clear();
			for (int i = 0; i < edges[idx].size(); ++i) {
				int v = edges[idx][i];
				sons.push_back(subs[idx][v]);
			}
			ans.push_back(idx);
			int pre = -1;
			for (int i = 1; i < n; ++i) {
				int maxv = 0, k = -1;
				for (int j = 0; j < sons.size(); ++j) {
					if (sons[j].size() >= maxv && j != pre) {
						maxv = sons[j].size();
						k = j;
					}
				}
				pre = k;
				ans.push_back(sons[k].back());
				sons[k].pop_back();
			}
			return ans;
		}
};
