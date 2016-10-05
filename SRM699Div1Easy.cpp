#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class OthersXor {
	public:
		int n;
		ll minSum (vector<int> x) {
			n = x.size();
			ll ans = 0LL;
			for (int i = 29; i >= 0; --i) {
				int res = n + 1;
				for (int j = 0; j < 2; ++j) {
					int cnt1 = 0;
					int cnt2 = 0;
					for (int k = 0; k < n; ++k) {
						if (x[k] != -1) {
							int bit = ((1<<i) & x[k]) > 0;
							cnt1 += (bit ^ j);
						} else {
							cnt2++;
						}
					}
					if ((cnt1 & 1) != j) {
						if (!cnt2) continue;
						res = min(res, cnt1 + 1);
					} else {
						res = min(res, cnt1);
					}
				}
				if (res > n) return -1;
				ans += (ll)res * (1LL << i);
			}
			return ans;
		}
};
