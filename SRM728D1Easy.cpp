#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define INT_MAX 2000000000
using namespace std;
class Halving {
	public:
		int n;
		int getres(int x, int y) {
			int tx = x;
			int cnt = 0;
			int res = INT_MAX;
			while(tx >= y) {
				if (tx == y) {
					res = min(res, cnt);
					break;
				}
				tx /= 2;
				cnt++;
			}
			tx = x;
			cnt = 0;
			while(tx >= y) {
				if (tx == y) {
					res = min(res, cnt);
					break;
				}
				if (tx & 1) tx = (tx + 1) / 2;
				else tx /= 2;
				cnt++;
			}
			return res == INT_MAX ? -1 : res;
		}
		int minSteps(vector<int> a) {
			n = a.size();
			int ans = INT_MAX;
			for (int i = 0; i < n; ++i) {
				int bits = 0;
				int x = a[i];
				while(x) {
					bits++;
					x /= 2;
				}
				int zn = 0;
				for (int j = 0; j < bits; ++j) {
					int res = 0;
					int k;
					for (k = 0; k < n; ++k) {
						int tmp = getres(a[k], a[i] >> j);
						if (tmp <0) break;
						res += tmp;
					}
					if (k >= n)
						ans = min(ans, res);
					if (zn) {
						res = 0;
						for (k = 0; k < n; ++k) {
							int tmp = getres(a[k], (a[i] >> j) + 1);
							if (tmp < 0) break;
							res += tmp;
						}
						if (k >= n) ans = min(ans, res);
					}
					if ((1<<j) & a[i]) zn++;
				}
			}
			return ans;
		}
};
