#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1002
using namespace std;
class GraphInversions {
	public:
		vector<int> edges[N];
		int n, k, m;
		bool vis[N];
		int ans;
		vector<int> v;
		int BIT[N];
		void insert(int pos, int val) {
			while(pos <= m) {
				BIT[pos] += val;
				pos += (pos & (-pos));
			}
		}
		int getsum(int pos) {
			int res = 0;
			while(pos > 0) {
				res += BIT[pos];
				pos -= (pos & (-pos));
			}
			return res;
		}
		void dfs(int cur, int par, int cnt, int sum) {
			if (vis[cur]) return;
			vis[cur] = true;
			int res = cnt - 1 - getsum(v[cur]) + sum;
			if (cnt >= k) {
				ans = min(ans, res);
			}
			insert(v[cur], 1);
			for (int i = 0; i < edges[cur].size(); ++i) {
				int u = edges[cur][i];
				if (u == par) continue;
				dfs(u, cur, cnt + 1, res);
			}
			vis[cur] = false;
			insert(v[cur], -1);
		}
		int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V, int K) {
			n = V.size();
			v = V;
			k = K;
			m = 0;
			for (int i = 0; i < n; ++i) {
				m = max(m, V[i]);
			}
			for (int i = 0; i < n; ++i) {
				edges[A[i]].push_back(B[i]);
				edges[B[i]].push_back(A[i]);
			}
			ans = n * n;
			for (int i = 0; i < n; ++i) {
				memset(vis, false, sizeof(vis));
				memset(BIT, 0, sizeof(BIT));
				dfs(i, -1, 1, 0);
			}
			return (ans == n * n ? -1 : ans);
		}
};
