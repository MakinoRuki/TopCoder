#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class VampireTree {
	public:
		int n;
		int maxDistance (vector<int> num) {
			n = num.size();
			int tot = 0;
			int cnt = 0;
			for (int i = 0; i < n; ++i) {
				tot += num[i];
				if (num[i] != 1) cnt++;
			}
			if (tot != 2 * (n - 1)) return -1;
			return cnt + 1;
		}
};
