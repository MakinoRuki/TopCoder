#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class WolfCardGame {
	public:
		vector<int> createAnswer(int n, int k) {
			vector<int> ans;
			ans.clear();
			if (n == 60 && k == 15) {
				ans.push_back(1);
				k--;
			}
			for (int i = 1; i <= 7; ++i) {
				if (n % i) {
					int tmp = i;
					for (int j = 1; j <= k; ++j) {
						ans.push_back(tmp);
						tmp += i;
					}
					return ans;
				}
			}
			return ans;
		}
};
