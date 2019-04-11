#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class OrthogonalProjections {
	public:
		vector<int> generate(int n) {
			vector<int> ans;
			if (n == 1) return {0,0};
			else if (n == 2) return {0, 0, 1, 1};
			else if (n == 4 || n % 2 == 1) {
				return {};
			} else {
				n /= 2;
				int m = 1;
				while(m * m < n) m++;
				for (int i = 0; i < m; ++i) {
					ans.push_back(0);
					ans.push_back(i);
				}
				ans.push_back(1);
				ans.push_back(0);
				n -= (m + 1);
				int s = 0;
				while(n) {
					int t = min(m, n);
					s += t;
					ans.push_back(1);
					ans.push_back(s);
					n -= t;
				}
			}
			return ans;
		}
};
