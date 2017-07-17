#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
typedef long long ll;
class CircleCity {
	public:
		int n;
		ll dis[N];
		bool check (ll mid, int k) {
			int res = 1;
			ll sum = 0;
			for (int i = 1; i < n;) {
				if (sum + dis[i] <= mid) {
					sum += dis[i];
					i++;
				} else {
					sum = 0;
					res++;
					i++;
				}
			}
			return res <= k;
		}
		int findMin (vector<int> dist, int k) {
			n = dist.size();
			ll ans = 3000000000LL;
			for (int i = 0; i < n; ++i) {
				memset(dis, 0, sizeof(dis));
				for (int j = 0; j < n - 1; ++j) {
					dis[j + 1] = dist[j];
				}
				ll l = 0, r = 3000000000LL;
				while (l < r) {
					ll mid = (l + r) / 2;
					if (check(mid, k)) {
						r = mid;
					} else {
						l = mid + 1;
					}
				}
				ans = min(ans, r);
				rotate(dist.begin(), dist.begin() + 1, dist.end());
			}
			return ans;
		}
};
