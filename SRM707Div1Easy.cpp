#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class MazeConstruct {
	public:
		vector<string> construct (int k) {
			vector<string> ans;
			ans.clear();
			if (k <= 98) {
				int r = min(k + 1, 50);
				for (int i = 0; i < r; ++i) {
					ans.push_back("");
					int c = k - (r - 1) + 1;
					for (int j = 0; j < c; ++j) {
						ans[i] += ".";
					}
				}
			} else {
				int dk = k - 98;
				int cc = 50;
				if (dk & 1) {
					dk = k - 97;
					cc = 49;
				}
				for (int i = 0; i < 50; ++i) {
					ans.push_back("");
					for (int j = 0; j < cc; ++j) {
						ans[i] += ".";
					}
				}
				for (int j = 3; j < cc; j += 4) {
					for (int i = 1; i < 50; ++i) {
						ans[i][j] = '#';
					}
				}
				int tr = 0, tc = 1;
				while (dk) {
					ans[tr][tc] = '#';
					dk -= 2;
					tr++;
					if (tr == 49) {
						tc += 4;
						tr = 0;
					}
				}
			}
			return ans;
		}
};
