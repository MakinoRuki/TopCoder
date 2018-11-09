#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class WakingUp {
	public:
		int n;
		int getlcm(int lcm, int val) {
			return lcm * val / __gcd(lcm, val);
		}
		int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D) {
			n = period.size();
			int tot = 0;
			int lcm = 1;
			for (int i = 0; i < n; ++i) {
				tot = max(tot, start[i]);
				lcm = getlcm(lcm, period[i]);
			}
			int accu = D * 2520;
			for (int i = 0; i < n; ++i) {
				accu -= volume[i] * 2520 / period[i];
			}
			if (accu < 0) return -1;
			tot += lcm;
			int val = 0;
			int ans = 1;
			for (int i = 1; i <= tot; ++i) {
				val += D;
				for (int j = 0; j < n; ++j) {
					if (i >= start[j] && (i - start[j]) % period[j] == 0) {
						val -= volume[j];
					}
				}
				ans = min(ans, val);
			}
			return -ans;
		}
};
