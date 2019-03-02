#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class AliceGame {
	public:
		ll findMinimumValue(ll x, ll y) {
			ll q = (ll)sqrt(x + y);
			if (q * q != x + y) return -1;
			ll ans = 0;
			for (ll i = q; i > 0; --i) {
				if (x == 0) return ans;
				if (2 * i - 1 <= x && x - 2 * i + 1 != 2) {
					x -= (2 * i - 1);
					ans++;
				}
			}
			return (x == 0 ? ans : -1);
		}
};

/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define N 2000000
using namespace std;
typedef long long ll;
ll lft[N], rit[N];
class AliceGame {
	public:
		ll findMinimumValue (ll x, ll y) {
			ll n = (ll)sqrt(x + y);
			if (n * n != (x + y)) {
				return -1;
			} 
			ll l = 0, r = 0;
			lft[0] = 0, rit[0] = 0;
			for (int i = 1; i <= n; ++i) {
				l += (ll)i;
				r += (n - (ll)i + 1LL);
				lft[i] = l, rit[i] = r;
			}
			for (ll i = 0; i <= n; ++i) {
				if ((x + i) & 1) {
					continue;
				} 
				if ((y + n - i) & 1) {
					continue;
				}
				ll A = (x + i) / 2LL;
				if (A >= lft[i] && A <= rit[i]) {
					return i;
				}
			}
			return -1;
		}
};*/
