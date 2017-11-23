#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int mod = 1000000007;
int dp[15][15][31][15][15][15];
class BuffaloBuffaloBuffalo {
	public:
		void update(int & val, int add) {
			val = (val + add) % mod;
		}
		int count(string pat) {
			int n = pat.size();
			if (n % 7) return 0;
			int m = n / 7;
			memset(dp, 0, sizeof(dp));
			dp[m][0][0][0][0][0] = 1;
			for (int i = 0; i < n; ++i) {
				vector<vector<int> > val;
				val.clear();
				for (int f = m; f >= 0; --f) {
					for (int e = m - f; e >= 0; --e) {
						for (int d = m - f - e; d >= 0; --d) {
							for (int c = 2 * (m - f - e - d); c >= 0; --c) {
								for (int b = m - f - e - d - c / 2; b >= 0; --b) {
									for (int a = m - f - e - d - c / 2 - b; a >= 0; --a) {
										int v = dp[a][b][c][d][e][f];
										if (!v) continue;
										if ((pat[i] == 'b' || pat[i] == '?') && a) update(dp[a - 1][b + 1][c][d][e][f], v);
										if ((pat[i] == 'u' || pat[i] == '?') && b) update(dp[a][b - 1][c + 2][d][e][f], v);
										if ((pat[i] == 'f' || pat[i] == '?') && c) {
											if (c % 2) update(dp[a][b][c - 1][d + 1][e][f], v);
											else val.push_back({a, b, c - 1, d, e, f, v});
										}
										if ((pat[i] == 'a' || pat[i] == '?') && d) update(dp[a][b][c][d - 1][e + 1][f], v);
										if ((pat[i] == 'l' || pat[i] == '?') && e) update(dp[a][b][c][d][e - 1][f + 1], v);
										if ((pat[i] == 'o' || pat[i] == '?') && f) val.push_back({a, b, c, d, e, f - 1, v});
										dp[a][b][c][d][e][f] = 0;
									}
								}
							}
						}
					}
				}
				for (int j = 0; j < val.size(); ++j) {
					vector<int> v = val[j];
					update(dp[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]], v[6]);
				}
			}
			return dp[0][0][0][0][0][0];	
		}
};
