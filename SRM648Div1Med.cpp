#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class KitayutaMart {
	public:
		bool check (ll limit, int n, int k) {
		    ll tot = 0LL;
		    for (int i = 0;; ++i) {
		    	if ((1LL << i) <= limit) {
		    		tot += min((ll)k, limit / (1LL<<i));
		    	} else {
		    		break;
		    	}
		    }
		    return tot >= n;
		}
		ll getPow (ll a, ll b) {
			ll res = 1LL;
			while (b) {
				if (b & 1) res = res * a % mod;
				a = a * a % mod;
				b /= 2;
			}
			return res;
		}
		int lastPrice (int n, int k) {
			ll sum = 0LL;
			int i;
			int times = 0;
			for (i = 0; ; ++i) {
				if ((1LL << i) >= k) break;
				sum += (1LL << i);
				if (sum >= n) break;
			}
			if ((1LL << i) >= k) {
				times = (n - sum) / k;
				if (times) times--;
				n -= times * k;
			}
			ll l = 1, r = 4LL * k;
			while (l < r) {
				ll mid = (l + r) / 2;
				if (check(mid, n, k)) r = mid;
				else l = mid + 1;
			}
			return r % mod * getPow(2, times) % mod;
		}
};
