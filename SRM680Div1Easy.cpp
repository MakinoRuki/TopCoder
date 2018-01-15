#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class BearFair {
	public:
		bool dp[N][N];
		string isFair(int n, int b, vector<int> ut, vector<int> qt) {
			vector<pii> qs;
			for (int i = 0; i < ut.size(); ++i) {
				qs.push_back(mp(ut[i], qt[i]));
			}
			if (qs.back().first < b) qs.push_back(mp(b, n));
			else if (qs.back().second != n) return "unfair";
			sort(qs.begin(), qs.end());
			memset(dp, false, sizeof(dp));
			dp[0][0] = true;
			int m = qs.size();
			for (int i = 0; i < m; ++i) {
				for (int ej = 0; ej <= (i == 0 ? 0 : qs[i - 1].second); ++ej) {
					if (!dp[i][ej]) continue;
					int del = qs[i].second - (i == 0 ? 0 : qs[i - 1].second);
					int ndel = qs[i].first - (i == 0 ? 0 : qs[i - 1].first);
					int nej = ndel / 2;
					int noj = ndel - nej;
					if (i > 0 && qs[i - 1].first & 1) swap(nej, noj);
					for (int j = 0; j <= nej && j <= del; ++j) {
						if (del - j > noj) continue;
						dp[i + 1][ej + j] = true;
					}
				}
			}
			return dp[m][n / 2] ? "fair" : "unfair";
		}
};
