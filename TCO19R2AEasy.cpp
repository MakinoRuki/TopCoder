#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class RulerMaker {
	public:
		vector<int> placeStickers(int n) {
			vector<int> ans;
			ans.clear();
			if (n == 3) {
				return {1, 2, 4};
			}
			for (int i = 1; i <= n/2; ++i) {
				ans.push_back(i);
			}
			for (int i = 1; i <= n - n / 2; ++i) {
				ans.push_back(n / 2 + i * (n / 2));
			}
			return ans;
		}
};
