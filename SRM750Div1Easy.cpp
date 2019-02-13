#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class IdenticalBags {
	public:
		ll makeBags(vector<ll>c, ll bs) {
			ll mx = 0;
			int n = c.size();
			for (int i = 0; i < n; ++i) {
				mx = max(mx, c[i]);
			}
			ll l = 0LL, r = mx;
			while(l < r) {
				ll m = (l + r + 1) / 2;
				ll cnt = bs;
				for (int i = 0; i < n; ++i) {
					if (c[i] >= m) {
						cnt -= c[i] / m;
						if (cnt <= 0) break;
					}
				}
				if (cnt <= 0) {
					l = m;
				} else {
					r = m - 1;
				}
			}
			return r;
		}
};
