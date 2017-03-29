#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class ConsecutiveOnes {
	public:
		vector<int> bits;
		bool check (ll num, int k) {
			int tot = 0;
			while (num) {
				if (num & 1) tot++;
				else tot = 0;
				num /= 2;
				if (tot >= k) return true;
			}
			return false;
		}
		ll get(ll n, int k) {
			if (check(n, k)) return n;
			bits.clear();
			ll tn = n;
			for (int i = 0; i < 50; ++i) {
				bits.push_back(tn % 2);
				tn /= 2;
			}
			ll ans = (1LL << 50) - 1LL;
			for (int i = k - 1; i < 50; ++i) {
				vector<int> tmp = bits;
				for (int j = i; j > i - k; --j) {
					tmp[j] = 1;
				}
				ll res = 0LL;
				for (int j = i - k + 1; j < 50; ++j) {
					res += (1LL << j) * tmp[j];
				}
				if (check(res, k)) ans = min(ans, res);
			}
			return ans;
		}
};
