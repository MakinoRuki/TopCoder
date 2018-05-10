#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class StablePairsDiv1 {
	public:
		vector<int> findMaxStablePairs(int n, int c, int k) {
			vector<int> ans;
			ans.clear();
			if (c < 4 && k > 1) return ans;
			int y = n, x = n - 1;
			for (int i = k; i >= 1; --i) {
				if (y <= 0 || x <= 0 || x == y) {
					ans.clear();
					return ans;
				}
				ans.push_back(y);
				ans.push_back(x);
				if (c % 2 == 0) {
					y -= c / 2;
					x -= c / 2;
				} else {
					if ((k - i) % 2 == 0) {
						y -= c / 2;
						x -= (c + 1) / 2;
					} else {
						y -= (c + 1) / 2;
						x -= c / 2;
					}
				}
			}
			reverse(ans.begin(), ans.end());
			return ans;
		}
};
