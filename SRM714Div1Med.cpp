#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
class NAddOdd {
	public:
		ll getNum(ll X, int K) {
			ll res = 0LL;
			while(X > K) {
				if (X & 1) X = (X + K) / 2, res += 2;
				else X /= 2, res++;
			}
			return res;
		}
		ll cal(ll X, int K) {
			if (X <= K) return 0;
			ll en = X / 2 - K / 2;
			ll on = X - K - en;
			ll ans = en + on * 2LL + 2LL * cal(X / 2, K);
			for (ll i = X / 2 + 1; i <= (X + K) / 2; ++i) {
				ans += getNum(i, K);
			}
			return ans;
		}
		ll solve(ll L, ll R, int K) {
			return cal(R, K) - cal(L - 1, K);
		}
};
