#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 310000
using namespace std;
typedef long long ll;
class MajoritySubarray {
	public:
		ll a[N];
		ll bit[N];
		ll getsum(int pos) {
			ll res = 0LL;
			while(pos > 0) {
				res += bit[pos];
				pos -= (pos & (-pos));
			}
			return res;
		}
		void add(int pos, int val) {
			while(pos <= n) {
				bit[pos] += val;
				pos += (pos & (-pos));
			}
		}
		ll getCount(int n, int seed, int m) {
			for (int i = 0; i < n; ++i) {
				a[i] = (seed / (1LL<<16) % m;
				seed = (seed * 1103515245LL + 12345LL) % (1LL<<31);
			}
			ll ans = 0LL;
			for (int i = 0; i < m; ++i) {
				ll sum = 0LL;
				memset(bit, 0LL, sizeof(bit));
				for (int j = 0; j < n; ++j) {
					if (a[j] == i) sum++;
					ll res = 2LL * sum - (j + 1) + n + 1;
					ans += getsum(res - 1);
					add(res, 1);
				}
			}
			return ans;
		}
};
