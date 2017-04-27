#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class PowerEquation {
	public:
		int count (int n) {
			set<int> ps;
			ps.clear();
			ll ans = (ll)n * (ll)n % mod * 2LL % mod;
			ans = (ans - (ll)n + mod) % mod;
			for (ll p = 2; p * p <= (ll)n; ++p) {
				if (ps.find(p) != ps.end()) continue;
				ll p1 = 1LL;
				for (int a = 1; a <= 30; ++a) {
					p1 = p1 * p;
					if (p1 > n || p1 < 0) break;
					ps.insert(p1);
					ll p2 = 1LL;
					for (int b = 1; b <= 30; ++b) {
						p2 = p2 * p;
						if (p2 > n || p2 < 0) break;
						if (a == b) continue;
						int d = __gcd(a, b);
						int ta = a / d, tb = b / d;
						ans = (ans + (ll)min(n / ta, n / tb)) % mod;
					}
				}
			}
			return ans;
		}
};
