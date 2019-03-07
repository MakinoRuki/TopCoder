#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class FightMonsterDiv1 {
	public:
		ll fightTime(ll hp, ll atk, int lev, ll dur) {
			if (atk >= hp) return 1;
			ll atk2 = atk / 100 * lev;
			ll l = 1, r = (atk2 == 0 ? hp / atk : (ll)sqrt(2LL * hp / atk2) + 1LL);
			while(l < r) {
				ll m = (l + r) / 2LL;
				ll res = atk * m + atk2 * m * (m - 1) / 2LL;
				if (m > dur) {
					res += 4 * dur * atk + 2LL * atk2 * dur * (2 * m - dur - 1);
				} else {
					res *= 5LL;
				}
				if (res >= hp) r = m;
				else l = m + 1;
			}
			return r + 1;
		}
};
