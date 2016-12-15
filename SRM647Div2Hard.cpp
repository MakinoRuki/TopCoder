#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
class BuildingTowers {
	public:
		bool check (int n, int k, vector<int> x, vector<int> t, ll value) {
			vector<pii> rank;
			rank.clear();
			for (int i = 0; i < x.size(); ++i) {
				if (value > t[i]) {
					ll delta = (value - t[i] - 1) / (ll)k;
					int l = max(1LL, x[i] - delta);
					int r = min(x[i] + delta, (ll)n);
					rank.push_back(mp(l, 0));
					rank.push_back(mp(r, 1));
				}
			}
			sort(rank.begin(), rank.end());
			int pre = 1;
			int sum = 0;
			for (int i = 0; i < rank.size(); ++i) {
				int add = (rank[i].second ? -1 : 1);
				if (sum == 0 && sum + add > 0) {
					if (rank[i].first - pre > 1) return true;
				}
				sum += add;
				if (sum == 0) pre = rank[i].first;
			}
			if (pre < n) return true;
			return false;
		}
		ll maxHeight (int n, int k, vector<int> x, vector<int> t) {
			x.push_back(1);
			t.push_back(0);
			ll l = 0LL, r = (ll)n * (ll)k;
			while (l < r) {
				ll mid = (l + r + 1LL) / 2LL;
				if (check(n, k, x, t, mid)) l = mid;
				else r = mid - 1;
			}
			return r;
		}
};
