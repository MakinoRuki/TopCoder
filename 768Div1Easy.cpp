#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class MeanMedian {
	public:
		int minEffort(int needMean, int needMedian, vector<int> d) {
			int n = d.size();
			int m = (n+1)/2 * needMedian;
			m = needMean * n - m;
			vector<int> ans(n, 0);
			sort(d.begin(), d.end());
			int tot=0;
			for (int i = 0; i < n; ++i) {
				if (i <= (n+1)/2-1) {
					ans[i] = needMedian;
					tot += ans[i] * d[i];
					if (m > 0) {
						int can = min(m, 10-ans[i]);
						ans[i] += can;
						tot += d[i] * can;
						m -= can;
					}
				} else {
					if (m > 0) {
						int can = min(m, ans[(n+1)/2-1]);
						ans[i] = can;
						tot += d[i] * ans[i];
						m -= can;
					}
				}
			}
			return tot;
		}
};
