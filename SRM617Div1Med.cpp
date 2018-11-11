#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 52
#define M 1002
using namespace std;
class PieOrDolphin {
	public:
		int n, m;
		int ind[N], outd[N];
		vector<int> res;
		int pv[N], pe[N];
		vector <int> Distribute(vector <int> c1, vector <int> c2) {
			n = 50;
			m = c1.size();
			memset(ind, 0, sizeof(ind));
			memset(outd, 0, sizeof(outd));
			for (int i = 0; i < m; ++i) {
				res.push_back(1);
				outd[c1[i]]++;
				ind[c2[i]]++;
			} 
			while(true) {
				int i;
				for (i = 0; i < n; ++i) {
					if (abs(ind[i] - outd[i]) >= 2) break;
				}
				if (i >= n) break;
				if (ind[i] > outd[i]) {
					for (int j = 0; j < m; ++j) {
						res[j] = res[j] % 2 + 1;
					}
					for (int j = 0; j < n; ++j) {
						swap(ind[j], outd[j]);
					}
				}
				queue<int> Q;
				bool vis[N];
				memset(vis, false, sizeof(vis));
				vis[i] = true;
				memset(pv, -1, sizeof(pv));
				memset(pe, -1, sizeof(pe));
				Q.push(i);
				int v = -1;
				while(!Q.empty()) {
					int cur = Q.front();
					Q.pop();
					if (ind[cur] > outd[cur]) {
						v = cur;
						break;
					}
					for (int j = 0; j < m; ++j) {
						int nxt = -1;
						if (res[j] == 1 && cur == c1[j]) {
							nxt = c2[j];
						} else if (res[j] == 2 && cur == c2[j]) {
							nxt = c1[j];
						}
						if (nxt < 0) continue;
						if (nxt != cur && !vis[nxt]) {
							vis[nxt] = true;
							pv[nxt] = cur;
							pe[nxt] = j;
							Q.push(nxt);
						}
					}
				}
				if (v < 0) break;
				while(v != i) {
					int u = pv[v];
					int e = pe[v];
					res[e] = res[e] % 2 + 1;
					outd[v]++;
					ind[v]--;
					ind[u]++;
					outd[u]--;
					v = u;
				}
			}
			return res;
		}
};
