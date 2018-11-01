#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
#define pii pair<int, int>
#define mp make_pair
using namespace std;
typedef long long ll;
class MinimumSquare {
	public:
		int n;
		ll minArea(vector<int> x, vector<int> y, int k) {
			n = x.size();
			vector<pii> pts;
			pts.clear();
			for (int i = 0; i < n; ++i) {
				pts.push_back(mp(x[i], y[i]));
			}
			sort(pts.begin(), pts.end());
			ll ans = -1;
			for (int i = 0; i < n; ++i) {
				for (int j = i; j < n; ++j) {
					ll detx = pts[j].first - pts[i].first + 2;
					vector<int> ys;
					ys.clear();
					for (int t = i; t <= j; ++t) {
						ys.push_back(pts[t].second);
					}
					sort(ys.begin(), ys.end());
					for (int t = 0; t + k <= ys.size(); ++t) {
						ll dety = ys[t + k - 1] - ys[t] + 2;
						ll det = max(detx, dety);
						ans = (ans < 0 ? det * det : min(ans, det * det));
					}
				}
			}
			return ans;
		}
};
