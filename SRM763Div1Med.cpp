#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200010
using namespace std;
typedef long long ll;
ll A[2*N];
ll E[N];
vector<int> edges[N];
ll V[N];
ll sum1[N], sum2[N];
ll sons[N];
class RootItRight {
	public:
		ll ans = -1;
		int n;
		void dfs1(int u, int p) {
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				if (v == p) continue;
				dfs1(v, u);
				sum1[u] += sum1[v] + sum2[v];
				sum2[u] += sum2[v];
				sons[u] += sons[v];
			}
			sum2[u] += (sons[u]+1)*(ll)V[u];
			sons[u]++; 
		}
		void dfs2(int u, int p, ll pre1, ll pre2) {
			ll res = sum1[u] + pre1 + pre2;
			ll pre = pre1+pre2;
			if (ans < 0) ans = res;
			else ans = min(ans, res);
			for (int i = 0; i < edges[u].size(); ++i) {
				int v = edges[u][i];
				if (v == p) continue;
				ll npre1 = sum1[u] - sum1[v] - sum2[v] + pre;
				ll npre2 = sum2[u] - sum2[v] - sons[v]*(ll)V[u];
				npre2 += pre2 + (ll)(n - sons[u]) * V[u];
				dfs2(v, u, npre1, npre2);
			}
		}
		ll findMinimumTotalCost(int nn, vector <int> edge, vector <int> val, int D, int seed, int MX) {
			n = nn;
			A[0] = seed;
			for (int i =1; i < 2*n; ++i) {
				A[i] = (A[i-1] * 1103515245LL + 12345) % 2147483648LL;
			}
			for (int i = 0; i < edge.size(); ++i) {
				E[i] = edge[i];
			}
			for (int i = edge.size(); i < n; ++i) {
				E[i] = (A[i] % min(i, D)) + i - min(i, D);
			}
			for (int i = 1; i < n; ++i) {
				edges[i].push_back(E[i]);
				edges[E[i]].push_back(i);
			}
			for (int i = 0; i < val.size(); ++i) {
				V[i] = val[i];
			}
			for (int i = val.size(); i < n; ++i) {
				V[i] = A[n+i] % (ll)MX;
			}
			memset(sum1, 0, sizeof(sum1));
			memset(sum2, 0, sizeof(sum2));
			memset(sons, 0, sizeof(sons));
			dfs1(0, -1);
			dfs2(0, -1, 0, 0);
			return ans;
		}
};
