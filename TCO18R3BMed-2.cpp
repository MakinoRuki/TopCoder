#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class TestProctoring {
	public:
		double expectedTime(vector<int> p, vector<int> q) {
			vector<double> pr;
			pr.clear();
			int n = p.size();
			for (int i = 0; i < n; ++i) {
				pr.push_back((double)p[i] / (double)q[i]);
			}
			double ans = 0.0;
			for (int i = 1; i < (1<<n); ++i) {
				double res = 1.0;
				for (int j = 0; j < n; ++j) {
					if ((1<<j) & i) res *= (1.0 - pr[j]);
				}
				if (__builtin_popcount(i) & 1) {
					ans += 1.0 / (1.0 - res);
				} else {
					ans -= 1.0 / (1.0 - res);
				}
			}
			return ans;
		}
};
