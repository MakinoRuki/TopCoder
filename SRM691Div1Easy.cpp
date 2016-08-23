#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
class Sunnygraphs {
	public:
		int n;
		bool vis[N];
		int idx[N];
		void check (int tar, int cnt, vector<int> & a) {
			memset(vis, false, sizeof(vis));
			int cur = tar;
			do {
				vis[cur] = true;
				idx[cur] += cnt;
				cur = a[cur];
			} while (!vis[cur]);
		}
		ll count (vector<int> a) {
			n = a.size();
			memset(idx, 0, sizeof(idx));
			check(0, 1, a);
			check(1, 2, a);
			int only0 = 0, only1 = 0, both = 0;
			for (int i = 0; i < n; ++i) {
				if (idx[i] == 1) only0++;
				if (idx[i] == 2) only1++;
				if (idx[i] == 3) both++;
			}
			int other = n - only0 - only1 - both;
			ll ans = 0LL;
			ans += ((1LL << both) - 1) * (1LL << (n - both));
			ans += ((1LL << only0) - 1) * ((1LL << only1) - 1) * (1LL << other);
			if (both) {
				ans += (1LL << other);
			}
			return ans;
		}
};
