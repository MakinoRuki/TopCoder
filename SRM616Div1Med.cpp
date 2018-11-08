#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class ColorfulCoins {
	public:
		int n;
		vector<ll> ratios;
		int minQueries (vector<ll> values) {
			n = values.size();
			ratios.clear();
			if (n == 1) return 1;
			for (int i = 0; i < n - 1; ++i) {
				ratios.push_back(values[i + 1] / values[i]);
			}
			sort(ratios.begin(), ratios.end());
			n--;
			ll tot = 0;
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				tot++;
				ll res = 1LL;
				int j;
				for (j = 1;;j++) {
					res *= (ll)ratios[i];
					if (res - 1LL >= tot) break;
				}
				ans = max(ans, j);
			}
			return ans;
		}
};
