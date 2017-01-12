#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define inf 1000000000
using namespace std;
class FoxConnection {
	public:
		int n;
		int son[N];
		int dp[N][N][N];
		int fox;
		string havefox;
		vector<int> edges[N];
		void dfs1(int cur, int par) {
			son[cur] = (havefox[cur - 1] == 'Y');
			for (int i = 0; i < edges[cur].size(); ++i) {
				int nxt = edges[cur][i];
				if (nxt == par) continue;
				dfs1(nxt, cur);
				son[cur] += son[nxt];
			}
		}
		int dfs2 (int cur, int par, int en, int fox) {
		//	if (f && cur == 3 && par == 4 && en == 0 && fox == 0) cout<<"ok!"<<endl;
			if (dp[cur][en][fox] >= 0) return dp[cur][en][fox];
			if (en >= edges[cur].size()) {
				return fox <= 1 ? 0 : inf;
			}
			dp[cur][en][fox] = inf;
			int nxt = edges[cur][en];
			if (nxt == par) return dp[cur][en][fox] = dfs2(cur, par, en + 1, fox);
			// watch out for case : fox == 0.
			for (int i = 0; i <= max(0, fox - 1); ++i) {
				dp[cur][en][fox] = min(dp[cur][en][fox], dfs2(nxt, cur, 0, i) + dfs2(cur, par, en + 1, fox - i) + abs(i - son[nxt]));
			}
			return dp[cur][en][fox];
		}
		int minimalDistance (vector<int> A, vector<int> B, string haveFox) {
			n = haveFox.size();
			havefox = haveFox;
			fox = 0;
			for (int i = 0; i < n; ++i) {
				if (haveFox[i] == 'Y') fox++;
			} 
			if (fox == 0) return 0;
			for (int i = 0; i < A.size(); ++i) {
				edges[A[i]].push_back(B[i]);
				edges[B[i]].push_back(A[i]);
			}
			int ans = inf;
			for (int i = 1; i <= n; ++i) {
				memset(son, 0, sizeof(son));
				dfs1(i, -1);
				memset(dp, -1, sizeof(dp));
				dfs2(i, -1, 0, fox);
				ans = min(ans, dp[i][0][fox]);
			}
			return ans;
		}
};
