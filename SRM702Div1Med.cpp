#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class RepeatedStrings {
	public:
		int n;
		string findKth (string s, int k) {
			n = s.size();
			vector<string> ans;
			ans.clear();
			ans.push_back("()");
			// There are at most total 9526 good strings when len <= 150.
			for (int i = 0; i < ans.size(); ++i) {
				string cur = ans[i];
				string res = cur;
				for (int j = 0; (j + 1) * cur.size() <= n; ++j) {
					ans.push_back("(" + res + ")");
					res += cur;
				}
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < ans.size(); ++i) {
				int idx = 0;
				for (int j = 0; j < n; ++j) {
					if (ans[i][idx] == s[j]) idx++;
				}
				if (idx == ans[i].size()) {
					if (--k == 0) return ans[i];
				}
			}
			return "";
		}
};
