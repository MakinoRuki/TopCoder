#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class AliceAndBobEasy {
	public:
		vector<int> make(int n) {
			vector<int> ans;
			ans.clear();
			for (int i = 0; i < n; ++i) {
				ans.push_back(1024 + i);
			}
			if (n % 2 == 0) {
				ans[n - 1] = 1023;
			}
			return ans;
		}
};
