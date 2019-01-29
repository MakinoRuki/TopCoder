#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#define N 500005
using namespace std;
typedef long long ll;
class CatchTheBeat {
	public:
		ll x[N], y[N];
		int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
			x[0] = x0;
			for (int i = 1; i < n; ++i) {
				x[i] = (x[i - 1] * a + b) % mod1; 
			}
			for (int i = 0; i < n; ++i) {
				x[i] = x[i] - offset;
			}
			y[0] = y0;
			for (int i = 1; i < n; ++i) {
				y[i] = (y[i - 1] * c + d) % mod2;
			}
			for (int i = 0; i < n; ++i) {
				//cout<<x[i]<<" "<<y[i]<<endl;
			}
			vector<pair<int, int> > pts;
			pts.clear();
			for (int i = 0; i < n; ++i) {
				if (y[i] >= abs(x[i]))
				pts.push_back(make_pair(y[i] - x[i], y[i] + x[i]));
			}
			sort(pts.begin(), pts.end());
			for (int i = 0; i < n; ++i) {
				//cout<<pts[i].first<<" "<<pts[i].second<<endl;
			}
			vector<int> dp;
			dp.clear();
			for (int i = 0; i < pts.size(); ++i) {
				int idx = upper_bound(dp.begin(), dp.end(), pts[i].second) - dp.begin();
				if (idx == dp.size()) {
					dp.push_back(pts[i].second);
				} else {
					dp[idx] = pts[i].second;
				}
			}
			return dp.size();
		}
};
