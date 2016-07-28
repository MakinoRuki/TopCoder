#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class ParenthesesDiv1Easy {
	public:
		int n;
		vector<int> ans;
		vector<int> stack;
		void update (int l, int r) {
			if (l > r) return;
			ans.push_back(stack[l]);
			ans.push_back(stack[r]);
		}
		vector<int> correct(string s) {
			ans.clear();
			stack.clear();
			int n = s.size();
			for (int i = 0; i < n; ++i) {
				if (s[i] == '(') {
					stack.push_back(i);
				} else {
					if (stack.size() != 0 && s[stack.back()] == '(') {
						stack.pop_back();
					} else {
						stack.push_back(i);
					}
				}
			}
			int sz = stack.size();
			if (sz & 1) {
				ans.push_back(-1);
			} else {
				if (!sz) return ans;
				int l = 0, r = 0;
				for (int i = 0; i < sz; ++i) {
					if (s[stack[i]] == '(') l++;
					else r++;
				}
				if (l == r) {
					update(0, sz / 2 - 1);
					update(sz / 2, sz - 1);
				} else {
					if (l > r) {
						update(0, r - 1);
						update(sz / 2, sz - 1);
					} else {
						update(0, sz / 2 - 1);
						update(sz - l, sz - 1);
					}
				}
			}
			return ans;
		}
};
