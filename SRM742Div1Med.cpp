#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class RandomConcat {
	public:
		double dp[1<<15][51];
		int n, m;
		int cnt[52][16], nxt[52][16];
		void getNext(const vector<string>& ps, const string& nd) {
			memset(cnt, 0, sizeof(cnt));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= nd.size(); ++j) {
					string tmp = nd.substr(0, j);
					for (int k = 0; k < ps[i].size(); ++k) {
						tmp += ps[i][k];
						while(tmp.size() > nd.size()) tmp.erase(tmp.begin());
						while(tmp != nd.substr(0, tmp.size())) tmp.erase(tmp.begin());
						if (tmp.size() == nd.size()) cnt[j][i]++;
					}
					nxt[j][i] = tmp.size();
				}
			}
		}
		double expectation(vector <string> pieces, string needle) {
			n = pieces.size();
			m = needle.size();
			for (int i = 0; i < (1<<n); ++i) {
				for (int j = 0; j <= m; ++j) {
					dp[i][j] = 0.0;
				}
			}
			getNext(pieces, needle);
			double ans = 0.0;
			dp[(1<<n) - 1][0] = 1.0;
			for (int i = (1<<n) - 1; i >= 0; --i) {
				for (int j = 0; j <= m; ++j) {
					for (int k = 0; k < n; ++k) {
						if ((1<<k) & i) {
							double pr = dp[i][j] / (double)__builtin_popcount(i);
							ans += pr * (double)cnt[j][k];
							dp[i ^ (1<<k)][nxt[j][k]] += pr;
						}
					}
				}
			}
			return ans;
		}
};
