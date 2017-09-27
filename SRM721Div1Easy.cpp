#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class RememberWords {
	public:
		ll getMax(ll d, ll w) {
			ll l = 0, r = w;
			while(l < r) {
				ll m = (l + r + 1) / 2;
				ll tot = 0;
				if (m - d + 1 < 0) {
					tot = m * (m + 1) / 2;
				} else {
					tot = d * (m + m - d + 1) / 2;
				}
				if (tot <= w) {
					l = m;
				} else {
					r = m - 1;
				}
			}
			return r;
		}
		ll getMin(ll d, ll w) {
			ll l = 0, r = w;
			while(l < r) {
				ll m = (l + r) / 2;
				ll tot = (m + m + d - 1) * d / 2;
				if (tot >= w) {
					r = m;
				} else {
					l = m + 1;
				}
			}
			return r;
		}
		string isPossible(int d1, int d2, int w1, int w2) {
			ll max1 = getMax(d1, w1);
			ll min1 = getMin(d1, w1);
			ll max2 = getMax(d2, w2);
			ll min2 = getMin(d2, w2);
			if (max1 + 1 < min2) return "Impossible";
			if (max2 + 1 < min1) return "Impossible";
			return "Possible";
		}
};
