#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 5000010
using namespace std;
typedef long long ll;
class CatAndMice {
	public:
		ll phi[N];
		bool prime[N];
		ll countDirections(int n, int c) {
			memset(prime, true, sizeof(prime));
			memset(phi, 0, sizeof(phi));
			for (int i = 2; i <= 5000000; ++i) {
				phi[i] = i;
			}
			for (int i = 2; i <= 5000000; ++i) {
				if (prime[i]) {
					for (int j = i; j <= 5000000; j += i) {
						prime[j] = false;
						phi[j] = phi[j] / i * (i - 1);
					}
				}
			}
			ll l = (n + c) / (c + 1);
			ll r = n / c;
			ll ans = 0LL;
			for (int i = l; i <= r; ++i) {
				if (i * (c + 1) > n) {
					ans += phi[i];
				}
			}
			ans *= 8;
			if (n == c) ans += 8;
			return ans;
		}
};
