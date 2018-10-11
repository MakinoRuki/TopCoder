#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class HungryCowsMedium {
	public:
		int n, m;
		bool check (ll t, vector<int>& a, vector<int>& p) {
			vector<ll> rem;
			rem.clear();
			for (int i = 0; i < m; ++i) {
				rem.push_back(t - p[i]);
			}
			for (int i = n - 1; i >= 0; --i) {
				ll c = a[i];
				for (int j = 0; j < m; ++j) {
					if (a[i] + p[j] > t) continue;
					ll delta = max(0LL, rem[j]);
					if (delta <= c) {
						rem[j] -= delta;
						c -= delta;
					} else {
						rem[j] -= c;
						c -= c;
					}
				}
				if (c > 0) return false;
			}
			return true;
		}
		ll getWellFedTime(vector<int> cA, vector<int> bP) {
			n = cA.size();
			m = bP.size();
			sort(cA.begin(), cA.end());
			sort(bP.begin(), bP.end());
			ll l = 0, r = 305000000000LL;
			while(l < r) {
				ll mid = (l + r) / 2LL;
				if (check(mid, cA, bP)) {
					r = mid;
				} else {
					l = mid + 1LL;
				}
			}
			return r;
		}
};
