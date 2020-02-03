#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class EncloseArea {
	public:
		void addans(vector<string>& ans, int x, int y) {
			if (ans[x-1][y-1] != '.') {
				ans[x-1][y-1] = '.';
			} else {
				ans[x-1][y-1] = '/';
			}
			if (ans[x-1][y] != '.') {
				ans[x-1][y] = '.';
			} else {
				ans[x-1][y] = '\\';
			}
			if (ans[x][y-1] != '.') {
				ans[x][y-1] = '.';
			} else {
				ans[x][y-1] = '\\';
			}
			if (ans[x][y] != '.') {
				ans[x][y] = '.';
			} else {
				ans[x][y] = '/';
			}
		}
		vector<string> enclose(int A) {
			vector<pair<pair<int, int>, int>> rows;
			rows.clear();
			for (int i = 1; i < 50; ++i) {
				if (i == 1) {
					rows.push_back(make_pair(make_pair(1, 1), 1));
				} else {
					int size = (i <= 25 ? rows.back().second+2 : rows.back().second-2);
					rows.push_back(make_pair(make_pair(i, i), size));
				}
			}
			if (A % 2) return {};
			A /= 2;
			vector<string> ans;
			ans.clear();
			for (int i = 0; i < 50; ++i) {
				string s(50, '.');
				ans.push_back(s);
			}
			for (int i = 0; i < rows.size(); ++i) {
				int x = rows[i].first.first;
				int y = rows[i].first.second;
				int sz = rows[i].second;
				if (A == 0) break;
				A--;
				addans(ans, x, y);
				for (int j = 1; j <= sz/2; ++j) {
					if (A == 0) break;
					if (A) {
						addans(ans, x-j, y+j);
						A--;
					}
					if (A) {
						addans(ans, x+j, y-j);
						A--;
					}
				}
			}
			if (A) return {};
			return ans;
		}
};
