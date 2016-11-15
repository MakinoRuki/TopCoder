#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 502
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class HatParade {
	public:
		int n;
		ll tot;
		bool vis[N];
		int getPermutation (vector<int> value, vector<int> sum) {
			n = value.size();
			memset(vis, false, sizeof(vis));
			ll ans = 1LL;
			ll lsum = 0LL, rsum = 0LL;
			tot = 0LL;
			for (int i = 0; i < n; ++i) {
				tot += (ll)value[i];
			}
			for (int i = 1; i <= n; ++i) {
				int idx = -1, cnt = 0;
				for (int j = 0; j < n; ++j) {
					if (vis[j]) continue;
					if (lsum <= rsum) {
						if (lsum + value[j] == sum[j] || tot - lsum == sum[j]) {
							cnt++;
							if (idx == -1) idx = j;
						}
					} else {
						if (rsum + value[j] == sum[j] || tot - rsum == sum[j]) {
							cnt++;
							if (idx == -1) idx = j;
						}
					}
				}
				if (cnt == 0) return 0;
				if (cnt > 2 && lsum != rsum) return 0;
				if (lsum <= rsum) {
					if ((lsum || rsum) && lsum == rsum && i != n) {
						ans = ans * 2LL % mod;
					}
					lsum += value[idx];
					vis[idx] = true;
				} else {
					rsum += value[idx];
					vis[idx] = true;
				}
			}
			if (n > 1) ans = ans * 2LL % mod;
			return ans;
		}
};
