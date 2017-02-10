#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define inf 1LL<<60
using namespace std;
typedef long long ll;
class MultiplyAddPuzzle {
	public:
		ll minimalSteps (ll s, ll t, ll a, ll b) {
			ll ans = inf;
			if (s == t) return 0;
			if (b == 0) {
				if (a == 0) return (t == 0 ? 1 : -1);
				if (t % a == 0) ans = min(ans, t / a + 1);
				if (s <= t && ((t - s) % a == 0)) ans = min(ans, (t - s) / a);
			} 	
			if (b == 1) {
				if (a == 0) return -1;
				if (s <= t && ((t - s) % a == 0)) {
					ans = min(ans, (t - s) / a);
				}		
			}
			if (b <= 1) return ans < inf ? ans : -1;
			ll pw = 1LL;
			ll num = 0LL;
			while (true) {
				if (t < s * pw) break;
				// In case of overflow
				if (s * pw / pw != s) break;
				if (t == s * pw) {
					ans = min(ans, num);
				}
				if (a && ((t - s * pw) % a == 0)) {
					ll left = (t - s * pw) / a;
					ll res = num;
					ll tpw = 1;
					while (tpw < pw) {
						res += left % b;
						tpw *= b;
						left /= b;
					}
					res += left;
					ans = min(ans, res);
				}
				// In case of overflow
				if (pw * b > t || pw * b / b != pw) break;
				pw *= b;
				num++;
			}
			return ans == inf ? -1 : ans;
		}
};
