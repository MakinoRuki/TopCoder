#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Subgraphs {
	public:
		vector<string> findGroups(int k) {
			vector<string> ans;
			ans.clear();
			int n = 2 * k - 1;
			for (int i = 0; i < n; ++i) {
				string row(n, '0');
				if (i < k) {
					for (int j = 0; j < k; ++j) {
						if (i != j) row[j] = '1';
					}
				} else {
					int d = i - k;
					for (int j = d + 1; j < k; ++j) {
						row[j] = '1';
					}
				}
				ans.push_back(row);
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i != j && ans[i][j] == '0') {
						if (ans[j][i] == '1') ans[i][j] = '1';
					}
				}
			}
			for (int i = 1; i <= k; ++i) {
				string row(n, 'N');
				for (int j = 0; j <= k - i; ++j) {
					row[j] = 'Y';
				}
				if (i > 1) {
					for (int t = k; t <= 2 * k - i; ++t) {
						string row1 = row;
						row1[t] = 'Y';
						for (int p = 2 * k - i + 1; p <= 2 * k - 2; ++p) {
							row1[p] = 'Y';
						}
						ans.push_back(row1);
					}
				} else {
					ans.push_back(row);
				}
			}
			reverse(ans.begin() + n, ans.end());
			return ans;
		}
};
