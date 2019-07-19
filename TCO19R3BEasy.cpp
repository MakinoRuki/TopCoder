#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 102
using namespace std;
typedef long long ll;
const ll inf = 1LL<<62;
class TwoLadders {
	public:
		int n;
		ll dp[N][N];
		vector<int> ys;
		ll minSteps(int sx, int lx1, int lx2, vector<int> x, vector<int> y) {
			ys.clear();
			n = x.size();
			set<int> yss;
			yss.clear();
			for (int i = 0; i < n; ++i) {
				yss.insert(y[i]);
			}
			vector<int> ys(yss.begin(), yss.end());
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j <= n; ++j) {
					dp[i][j] = inf;
				}
			}
			x.push_back(sx);
			y.push_back(0);
			dp[0][n] = 0;
			int py = 0;
			for (int i = 0; i < ys.size(); ++i) {
				vector<pair<int, int> > xs;
				xs.clear();
				for (int j = 0; j < n; ++j) {
					if (y[j] == ys[i]) {
						xs.push_back({x[j], j});
					}
				}
				sort(xs.begin(), xs.end());
				for (int j = 0; j <= n; ++j) {
					if (dp[i][j] < inf) {
						if (py < ys[i]) {
							ll c1 = (ll)abs(x[j]-lx1)+(ll)(ys[i]-py)+(ll)abs(lx1-xs[0].first)+(ll)(xs.back().first-xs[0].first);
							ll c2 = (ll)abs(x[j]-lx1)+(ll)(ys[i]-py)+(ll)abs(lx1-xs.back().first)+(ll)(xs.back().first-xs[0].first);
							ll c3 = (ll)abs(x[j]-lx2)+(ll)(ys[i]-py)+(ll)abs(lx2-xs[0].first)+(ll)(xs.back().first-xs[0].first);
							ll c4 = (ll)abs(x[j]-lx2)+(ll)(ys[i]-py)+(ll)abs(lx2-xs.back().first)+(ll)(xs.back().first-xs[0].first);
							dp[i+1][xs[0].second] = min(dp[i+1][xs[0].second], dp[i][j]+min(c2, c4));
							dp[i+1][xs.back().second] = min(dp[i+1][xs.back().second], dp[i][j]+min(c1, c3));
						} else {
							ll c1 = (ll)abs(x[j]-xs[0].first)+(ll)abs(xs[0].first-xs.back().first);
							ll c2 = (ll)abs(x[j]-xs.back().first)+(ll)abs(xs[0].first-xs.back().first);
							dp[i+1][xs[0].second] = min(dp[i+1][xs[0].second], dp[i][j]+c2);
							dp[i+1][xs.back().second] = min(dp[i+1][xs.back().second], dp[i][j]+c1);
						}
					}
				}
				py = ys[i];
			}
			ll ans = inf;
			for (int i = 0; i <= n; ++i) {
				ans = min(ans, dp[ys.size()][i]);
			}
			return ans;
		}
};
