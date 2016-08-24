#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
class Undiv2 {
	public:
		ll getGcd (ll a, ll b) {
			return b == 0 ? a : getGcd(b, a % b);
		}
		ll getLcm (ll a, ll b) {
			ll gcd = getGcd(a, b);
			return (a / gcd) * b;
		}
		ll getsum (int n) {
			ll ans = 0LL;
			for (int i = 1; i <= 25; ++i) {
				for (int j = 1; j < i; ++j) {
					ll lcm = 1LL;
					for (int k = 1; k <= i; ++k) {
						if (i == k || k == j) continue;
						lcm = getLcm(lcm, (ll)k);
						if (lcm > n) break;
					}
					ll tot = n / lcm;
					ll lcm1 = getLcm(lcm, (ll)i);
					ll lcm2 = getLcm(lcm, (ll)j);
					ll lcm3 = getLcm(lcm1, lcm2);
					tot -= n / lcm1;
					tot -= n / lcm2;
					tot += n / lcm3;
					ans += tot * (ll)i;
				}
			}
			return ans;
		}
};
