#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class PeriodicJumping {
	public:
		int n;
		int minimalTime(int x, vector <int> jL) {
			x = abs(x);
			n = jL.size();
			ll tot = 0LL;
			ll mx = 0LL;
			if (x == 0) return 0;
			for (int i = 0; i < 2 * n; ++i) {
				tot += jL[i % n];
				mx = max(mx, (ll)jL[i % n]);
				if (tot >= x && mx * 2 <= tot + x) return i + 1;
			}
			tot /= 2;
			if (x / tot == 0) return -1;
			ll ans = x / tot * n;
			x %= tot;
			if (x == 0) return ans;
			for (int i = 0; i < n; ++i) {
				x -= jL[i];
				ans++;
				if (x <= 0) return ans;
			}
			return -1;
		}
};
