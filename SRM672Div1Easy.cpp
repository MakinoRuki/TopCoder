#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
class Procrastination {
	public:
		ll findFinalAssignee(ll n) {
			vector<ll>num(1000, 0);
			ll l = max(1LL, n - 400), r = n + 400;
			int pos = 0;
			for (int i = 0; i < (r - l + 1); ++i) {
				num[i] = i + l;
				if (i + l == n) pos = i;
			}
			for (ll h = 2; pos + l >= 2 * h;) {
				for (ll j = max(2LL * h, (l + h - 1) / h * h); j <= r; j += h) {
					if (num[j - l] == n) pos++;
					else if (num[j - l + 1] == n) pos--;
					swap(num[j - l], num[j - l + 1]);
				}
				if (h <= 1000000 || l / (h + 1) != r / (h + 1)) h++;
				else h = l / (l / (h + 1));
			}
			return pos + l;
		}
};


/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll, vector<ll> > > cache;
class Procrastination {
	public:
		ll find (ll n, ll pre) {
			int k;
			for (k = 0; k < cache.size(); ++k) {
				if (cache[k].first == n) {
					break;
				}
			}
			vector<ll> factor;
			if (k < cache.size()) {
				factor = cache[k].second;
			} else {
				for (ll i = 2; i * i <= n; ++i) {
					if (n % i == 0) {
						factor.push_back(i);
						if (i != n / i) factor.push_back(n / i);
					}
				}
			}
			ll res = n;
			for (int i = 0; i < factor.size(); ++i) {
				if (factor[i] > pre) res= min(res, factor[i]);
			}
			if (k == cache.size()) cache.push_back(make_pair(n, factor));
			return res;
		}
		ll findFinalAssignee (ll n) {
			ll pre = 1;
			cache.clear();
			while (true) {
				if (n == 2) {
					return n;
				}
				if (pre >= n) return n;
				ll res1 = find(n - 1, pre);
				ll res2 = find(n, pre);
				if (res1 < res2) {
					if (res1 == n - 1) return n;
					n--;
					pre = res1;
				} else if (res1 > res2) {
					n++;
					pre = res2;
				}
			}
			return n;
		}
};*/
