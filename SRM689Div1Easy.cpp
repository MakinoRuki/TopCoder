#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
class ColorfulGarden {
	public:
		int n;
		vector<pii> rank;
		vector<string> ans;
		vector<string> rearrange (vector<string> garden) {
			n = garden[0].size();
			int cnt[26];
			memset(cnt, 0, sizeof(cnt));
			rank.clear();
			ans.clear();
			for (int i = 0; i < 2; ++i) {
				ans.push_back("");
				for (int j = 0; j < n; ++j) {
					cnt[garden[i][j] - 'a']++;
					ans[i] += " ";
				}
			}
			for (int i = 0; i < 26; ++i) {
				if (cnt[i]) {
					if (cnt[i] > n) {
						ans.clear();
						return ans;
					}
					rank.push_back(mp(cnt[i], i));
				}	
			}
			sort(rank.begin(), rank.end());
			int cur = rank.size() - 1;
			int r = 0, c = 0;
			while (cur >= 0) {
				char ch = rank[cur].second + 'a';
				ans[r][c] = ch;
				rank[cur].first--;
				if (rank[cur].first == 0) cur--;
				r = (r + 1) % 2;
				c = (c + 1) % n;
				if (c == 0) r = 1;
			}
			for (int j = 0; j < n - 1; ++j) {
				if (ans[0][j] == ans[1][j]) {
					ans.clear();
					return ans;
				} else if (ans[0][j] == ans[0][j + 1] || ans[1][j] == ans[1][j + 1]) {
					ans.clear();
					return ans;
				}
			}
			return ans;
		}
};
