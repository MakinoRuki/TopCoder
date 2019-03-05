#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class UnreliableRover {
	public:
		int n;
		ll getArea(string dir, vector<int> minS, vector<int> maxS) {
			n = dir.size();
			ll yw = 1, xw = 1;
			ll s = 0;
			vector<ll> var;
			var.clear();
			vector<ll> cor;
			cor.clear();
			for (int i = 0; i < n; ++i) {
				if (dir[i] == '?') {
					s += maxS[i];
					var.push_back(maxS[i]);
				} else {
					if (dir[i] == 'N' || dir[i] == 'S') yw += maxS[i] - minS[i];
					if (dir[i] == 'E' || dir[i] == 'W') xw += maxS[i] - minS[i];
				}
			}
			ll ans = xw * yw + 2 * (xw + yw) * s;
			for (int i = 0; i < (1 << var.size()); ++i) {
				ll t = 0;
				for (int j = 0; j < var.size(); ++j) {
					if ((1<<j) & i) t += var[j];
				}
				cor.push_back(t);
			}
			sort(cor.begin(), cor.end());
			for (int i = 0; i < cor.size(); ++i) {
				if (i > 0) ans += (cor[i] - cor[i - 1]) * (s - cor[i]) * 4LL;
			}
			return ans;
		}
};
