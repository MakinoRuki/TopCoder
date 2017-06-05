#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
long double tsum2[N][N], tsum3[N][N];
long double tnum[N][N], tsum[N][N];
class AverageVarianceSubtree {
	public:
		int n;
		vector<int> edges[N];
		long double ws[N];
		int dfs (int cur, int limit) {
			int son = 1;
			tnum[cur][1] = 1;
			tsum[cur][1] = ws[cur];
			tsum2[cur][1] = tsum3[cur][1] = ws[cur] * ws[cur];
			for (int i = 0; i < edges[cur].size(); ++i) {
				int nxt = edges[cur][i];
				if (nxt > limit) {
					int sonn = dfs(nxt, nxt);
					long double ttnum[52] = {};
					long double ttsum[52] = {};
					long double ttsum2[52] = {};
					long double ttsum3[52] = {};
					for (int j = 1; j <= son + sonn; ++j) {
						for (int k = 0; k <= sonn; ++k) {
							if (j - k <= 0 || j - k > son) continue;
							int t = j - k;
							ttnum[j] += tnum[cur][t] * tnum[nxt][k];
							ttsum[j] += tsum[cur][t] * tnum[nxt][k] + tsum[nxt][k] * tnum[cur][t];
							ttsum2[j] += tsum2[cur][t] * tnum[nxt][k] + tsum2[nxt][k] * tnum[cur][t];
							ttsum3[j] += tsum3[cur][t] * tnum[nxt][k] + tsum3[nxt][k] * tnum[cur][t] + 2 * tsum[cur][t] * tsum[nxt][k];
						}
					}
					son += sonn;
					for (int j = 1; j <= son; ++j) {
						tnum[cur][j] = ttnum[j];
						tsum[cur][j] = ttsum[j];
						tsum2[cur][j] = ttsum2[j];
						tsum3[cur][j] = ttsum3[j];
					}
				}
			}
			tnum[cur][0] = 1;
			return son;
		}
		double average (vector<int> p, vector<int> w) {
			n = w.size();
			///////////////////////////// ws[i] = w[i] - sigma(w[i]) / n ... As the difference is third power, need to reduce ?? ////////////////////
			long double sum = 0;
			for (int i = 0; i < n; ++i) {
				ws[i] = (long double)w[i];
				sum += ws[i];
			}
			sum /= n;
			for (int i = 0; i < n; ++i) {
				ws[i] -= sum;
			}
			///////////////////////////// ws[i] = w[i] - sigma(w[i]) / n ... As the difference is third power, need to reduce ?? ////////////////////
			for (int i = 1; i < n; ++i) {
				edges[i].push_back(p[i - 1]);
				edges[p[i - 1]].push_back(i);
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 1; j <= n; ++j) {
					tnum[i][j] = 0;
					tsum2[i][j] = 0;
					tsum3[i][j] = 0;
				}
			}
			dfs(0, 0);
			long double tots = 0, totn = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 1; j <= n; ++j) {
			//		cout<<i<<" "<<j<<" "<<tsum2[i][j]<<" "<<tsum3[i][j]<<" "<<tnum[i][j]<<endl;
					tots += (tsum2[i][j] / j - tsum3[i][j] / j / j);
					totn += tnum[i][j];
				}
			}
			return tots / totn;
		}
};
