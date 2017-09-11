#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class RainbowGraph {
	public:
		int n, m;
		ll predp[12][N][N];
		ll dp[1<<11][N];
		vector<int> pts[12];
		bool mat[N][N];
		int countWays (vector<int> col, vector<int> a, vector<int> b) {
			n = col.size();
			m = a.size();
			memset(dp, 0, sizeof(dp));
			memset(predp, 0, sizeof(predp));
			memset(mat, false, sizeof(mat));
			for (int i = 0; i < m; ++i) {
				mat[a[i]][b[i]] = mat[b[i]][a[i]] = true;
			}
			int tot = 0;
			for (int i = 0; i < 10; ++i) {
				for (int j = 0; j < n; ++j) {
					if (col[j] == i) {
						tot |= (1<<i);
						pts[i].push_back(j);
					}
				}
			}
			for (int s = 0; s < n; ++s) {
				memset(dp, 0, sizeof(dp));
				int c = col[s];
				int i;
				for (i = 0; i < pts[c].size(); ++i) {
					if (pts[c][i] == s) break;
				}
				dp[1<<i][i] = 1LL;
				int nn = pts[c].size();
				for (int i = 1; i < (1<<nn); ++i) {
					for (int j = 0; j < nn; ++j) {
						if (!dp[i][j]) continue;
						if (!(i & (1 << j))) continue;
						for (int k = 0; k < nn; ++k) {
							if (i & (1 << k)) continue;
							if (!mat[pts[c][j]][pts[c][k]]) continue;
							dp[i | (1 << k)][k] = (dp[i | (1 << k)][k] + dp[i][j]) % mod;
						}
					}
				}
				for (int i = 0; i < nn; ++i) {
					predp[c][s][pts[c][i]] = dp[(1<<nn) - 1][i];
				}
			}
			cout<<predp[2][6][7]<<endl;
		//	cout<<predp[0][0]<<" "<<predp[0][1]<<" "<<predp[0][2]<<" "<<predp[1][3]<<" "<<predp[1][4]<<" "<<predp[1][5]<<" "<<predp[2][6]<<" "<<predp[2][7]<<" "<<predp[2][8]<<endl;
			memset(dp, 0, sizeof(dp));
			dp[0][n] = 1LL;
			for (int i = 0; i < (1<<10); ++i) {
				for (int j = 0; j <= n; ++j) {
					if (dp[i][j]) {
						for (int s = 0; s < n; ++s) {
							if (j != n && !mat[j][s]) continue;
							int c = col[s];
							if ((i & (1 << c))) continue;
							for (int k = 0; k < pts[c].size(); ++k) {
								dp[i | (1<<c)][pts[c][k]] = (dp[i | (1<<c)][pts[c][k]] + dp[i][j] * predp[c][s][pts[c][k]] % mod) % mod;
							}
						}
					}
				}
			}
			ll ans = 0LL;
			for (int i = 0; i < n; ++i) {
				ans = (ans + dp[tot][i]) % mod;
			}
			return ans;
		}
};
