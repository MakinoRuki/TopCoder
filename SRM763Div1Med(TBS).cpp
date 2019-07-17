#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 400010
using namespace std;
typedef long long ll;
class RootItRight {
	public:
		ll A[N];
		ll E[N];
		vector<int> edges[N];
		ll V[N];
		ll sum1[N], sum2[N];
		ll sons[N];
		ll ans = -1;
		void dfs1(int u) {
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				dfs1(v);
				sum1[u] += sum1[v];
				sum2[u] += sum2[v];
				sons[u] += sons[v];
			}
			sum1[u] += sum2[u] + (sons[u]+1)*(ll)V[u];
			sum2[u] += (sons[u]+1)*(ll)V[u];
			sons[u]++; 
		}
		void dfs2(int u, int p) {
			ll res = sum1[u];
			ll res2 = 0;
			if (p >= 0) {
				res2 = sum1[u]+sum2[u]+(sons[u]+1)*(ll)V[p];
				res2 = sum1[p] - res2;
				ll res3 = 0;
				res3 = sum2[p] - (sum2[u] + (sons[u]+1)*(ll)V[p]);
				res += (res2+res3+(sons[p]-sons[u]+1)*(ll)V[u]);
			}
			ans = max(ans, res);
		}
		ll findMinimumTotalCost(int N, vector <int> edge, vector <int> val, int D, int seed, int MX) {
			A[0] = seed;
			for (int i =1; i < 2*N; ++i) {
				A[i] = (A[i-1] * 1103515245LL + 12345) % 2147483648LL;
			}
			for (int i = 0; i < edge.size(); ++i) {
				E[i] = edge[i];
			}
			for (int i = edge.size(); i < N; ++i) {
				E[i] = (A[i] % min(i, D)) + i - min(i, D);
			}
			for (int i = 1; i < N; ++i) {
				edges[i].push_back(E[i]);
				edges[E[i]].push_back(i);
			}
			for (int i = 0; i < val.size(); ++i) {
				V[i] = val[i];
			}
			for (int i = val.size(); i < N; ++i) {
				V[i] = A[N+i] % MX;
			}
			memset(sum1, 0, sizeof(sum1));
			memset(sum2, 0, sizeof(sum2));
			memset(sons, 0, sizeof(sons));
			dfs1(0);
			dfs2(0, -1);
			return ans;
		}
};
