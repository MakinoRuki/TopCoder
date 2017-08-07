#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class ScoresSequence {
	public:
		int n;
		int cnt[N];
		int g[N][N];
		int count(vector<int> s) {
			n = s.size();
			vector<pii> rank;
			rank.clear();
			for (int i = 0; i < n; ++i) {
				rank.push_back(mp(s[i], i));
			}
			memset(g, 0, sizeof(g));
			for (int i = n - 1; i >= 0; --i) {
				g[i][i] = 1;
				sort(rank.begin(), rank.begin() + i + 1);
				for (int j = 0; j < rank[i].first; ++j) {
					g[rank[i].second][rank[j].second] = 1;
				}
				for (int j = rank[i].first; j < i; ++j) {
					g[rank[j].second][rank[i].second] = 1;
					rank[j].first--;
				}
			}
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						g[i][j] = g[i][j] || (g[i][k] && g[k][j]);
					}
				}
			}
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					ans += g[i][j];
				}
			}
			return ans;
		}
};
