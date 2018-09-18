#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
class RewardOnATree {
	public:
		int n;
		vector<int> edges[N];
		vector<int> lev[N];
		int lm[N], rm[N];
		int collect(vector<int> parent, vector<int> reward) {
			n = reward.size();
			for (int i = 1; i < n; ++i) {
				edges[parent[i - 1]].push_back(i);
			}
			lev[0].push_back(0);
			for (int i = 0; i < n; ++i) {
				if (lev[i].size() > 0) {
					for (int j = 0; j < lev[i].size(); ++j) {
						int u = lev[i][j];
						for (int k = 0; k < edges[u].size(); ++k) {
							int v = edges[u][k];
							lev[i + 1].push_back(v);
						}
					}
				}
			}
			int co[N], mu[N];
			memset(co, 0, sizeof(co));
			memset(mu, 0, sizeof(mu));
		//	memset(positive, 0, sizeof(positive));
			for (int i = n - 1; i >= 0; --i) {
				int positive = 0;
				for (int& u : lev[i]) {
				//	int u = lev[i][j];
					if (reward[u] >= 0) positive += reward[u];
					co[u] = 0;
					for (int& v : edges[u]) {
					//	int v = edges[u][k];
						co[u] = max(co[u], mu[v]);
					}
					co[u] += reward[u];
				}
				for (int j = 0; j < lev[i].size(); ++j) {
					int v = lev[i][j];
					int w = co[v];
					if (reward[v] > 0) w -= reward[v];
					if (j == 0) lm[j] = w;
					else lm[j] = max(lm[j - 1], w);
				}
				for (int j = lev[i].size() - 1; j >= 0; --j) {
					int v = lev[i][j];
					int w = co[v];
					if (reward[v] > 0) w -= reward[v];
					if (j == lev[i].size() - 1) rm[j] = w;
					else rm[j] = max(rm[j + 1], w);
				}
				for (int j = 0; j < lev[i].size(); ++j) {
					int u = lev[i][j];
					mu[u] = reward[u];
					int tv = positive;
					if (reward[u] > 0) tv -= reward[u];
					mu[u] = max(mu[u], co[u] + tv);
					if (j > 0) mu[u] = max(mu[u], lm[j - 1] + reward[u] + tv);
					if (j < lev[i].size() - 1) mu[u] = max(mu[u], rm[j + 1] + reward[u] + tv);
				//	cout<<u<<" "<<mu[u]<<endl;
				}
			}
			return mu[0];
		}
};
