#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000005
using namespace std;
typedef long long ll;
ll table[N];
class TheRoundCityDiv1 {
	public:
		ll find(int r) {
			memset(table, -1, sizeof(table));
			for (int i = 2; i < N; ++i) {
				for (int j = i; j < N; j += i) {
					if (table[j] == -1) table[j] = i;
				}
			}
			ll ans = 0LL;
			for (ll a = 1LL; a <= r; ++a) {
				ll b = (ll)sqrt((ll)r * (ll)r - a * a);
				vector<ll> prs;
				prs.clear();
				ll x = a;
				while(x > 1) {
					ll p = table[x];
					prs.push_back(p);
					while(x % p == 0) x /= p;
				}
				ll sum = b;
				int sz = prs.size();
				for (int i = 1; i < (1<<sz); ++i) {
					int bt = __builtin_popcount(i);
					ll acc = 1LL;
					for (int j = 0; j < sz; ++j) {
						if ((1<<j) & i) acc *= prs[j];
					}
					if (bt & 1) sum -= b / acc;
					else sum += b / acc;
				}
				ans += 4LL * sum;
			}
			return ans + 4;
		}
};
