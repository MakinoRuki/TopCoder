#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class ColorfulLineGraphs {
	public:
		ll getPow (ll a, ll b, ll m) {
			ll res = 1LL;
			while (b) {
				if (b & 1) {
					res = res * a % m;
				}
				a = a * a % m;
				b /= 2;
			}
			return res;
		}
		int countWays (ll N, ll K, int M) {
			ll q = N / M;
			ll r = N % M;
			ll ans = 1LL;
			for (ll i = 1; i <= M; ++i) {
				ll res = K + (i - 1) * (K - 1);
				res %= M;
				if (i <= r) { 
					ans = ans * getPow(res, q + 1, M) % M;
				} else {
					ans = ans * getPow(res, q, M) % M;
				}
			}
			return ans;
		}
};
