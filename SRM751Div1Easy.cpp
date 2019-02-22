#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class Hyperbox {
public:
	int count(int vol) {
		if (vol % 2) return 0;
		vol /= 2;
		int ans = 0;
		for (ll a = 1; 4LL * a * a * a <= vol; ++a) {
			for (ll b = a; b * b * b + 3LL * a * b * b <= vol; ++b) {
				for (ll c = b; 2LL * a * b * c + a * c * c + b * c * c <= vol; ++c) {
					ll tmp = vol - a * b * c;
					if (tmp < 0) break;
					ll tmp2 = a * b + b * c + a * c;
					if (tmp % tmp2) continue;
					ll d = tmp / tmp2;
					if (d >= c) ans++;
				}
			}
		}
		return ans;
	}
};
