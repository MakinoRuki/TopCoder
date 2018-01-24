#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class TreeAndPathLength3 {
	public:
		vector<int> construct (int s) {
			int q = 1;
			for (q = 1; q <= 100; ++q) {
				if (q * q > s) break;
			}
			q--;
			vector<int> ans;
			ans.clear();
			ans.push_back(0);
			ans.push_back(1);
			for (int i = 1; i < q; ++i) {
				ans.push_back(0);
				ans.push_back(1 + i);
			}
			for (int i = 1; i < q; ++i) {
				ans.push_back(1);
				ans.push_back(q + i);
			}
			ans.push_back(1);
			ans.push_back(2 * q);
			ans.push_back(2 * q);
			ans.push_back(2 * q + 1);
			s -= q * q;
			for (int i = 1; i <= s; ++i) {
				ans.push_back(2 * q + 1);
				ans.push_back(2 * q + 1 + i);
			}
			return ans;
		}
};
