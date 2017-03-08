#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class Softmatch {
	public:
		int dp[N][5][N];
		int n, k;
		bool matches (char ch1, char ch2) {
			if (ch1 == 'a' && (ch2 - '0') >= 2) return false;
			if (ch1 == 'A' && (ch2 - '0') < 2) return false;
			if (ch1 == 'b' && ((ch2 - '0') % 2 != 0)) return false;
			if (ch1 == 'B' && ((ch2 - '0') % 2 == 0)) return false;
			return true;
		}
		bool matches (string s1, string s2, int len) {
			if (len > s1.size() || len > s2.size()) return false;
			for (int i = 0; i < len; ++i) {
				if (!matches(s1[s1.size() - len + i], s2[i])) return false;
			}
			return true;
		}
		int count (string s, vector<string> patterns) {
			n = s.size();
			k = patterns.size();
			memset(dp, -1, sizeof(dp));
			dp[0][0][0] = 0;
			for (int i = 0; i < n; ++i) {
				for (int p = 0; p < k; ++p) {
					for (int j = 0; j < patterns[p].size(); ++j) {
						if (dp[i][p][j] < 0) continue;
						string cur = "";
						for (int t = 0; t < j; ++t) {
							char ch = s[i - j + t];
							if (!matches(s[i - j + t], patterns[p][t])) {
								ch += 'A' - 'a';
							}
							cur += " ";
							cur[cur.size() - 1] = ch;
						}
						cur += " ";
						for (int nxt = 0; nxt < 2; ++nxt) {
							if (!nxt) cur[cur.size() - 1] = s[i];
							else cur[cur.size() - 1] = s[i] + 'A' - 'a';
							int add = 0;
							int nlen = 0, nidx = 0;
							for (int np = 0; np < k; ++np) {
								for (int nj = 0; nj <= patterns[np].size(); ++nj) {
									if (matches(cur, patterns[np], nj)) {
										if (nj == patterns[np].size()) add++;
										else if (nj > nlen){
											nlen = nj;
											nidx = np;
										}
									}
								}
							}
							auto & value = dp[i + 1][nidx][nlen];
							value = max(value, dp[i][p][j] + add);
						}
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < k; ++i) {
				for (int j = 0; j <= n; ++j) {
					ans = max(ans, dp[n][i][j]);
				}
			}
			return ans;
		}
};
