#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 502
using namespace std;
typedef long long ll;
class CutCutCut {
	public:
		ll dp[N];
		vector<int> ans;
		double cross(int x1, int y1, int x2, int y2, int x0, int y0) {
			double res = (double)(x0-x1)*(double)(y2-y1) - (double)(x2-x1)*(double)(y0-y1);
			return res;
		}
		bool insc(int x10, int y10, int x20, int y20, int x11, int y11, int x21, int y21) {
			double d1 = cross(x10, y10, x20, y20, x11, y11);
			double d2 = cross(x10, y10, x20, y20, x21, y21);
			double d3 = cross(x11, y11, x21, y21, x10, y10);
			double d4 = cross(x11, y11, x21, y21, x20, y20);
			if (d1*d2 < 0 && d3 * d4 < 0) {
				return true;
			}
			return false;
		}
		vector <int> findPieces(vector <int> x1, vector <int> y1, vector <int> x2, vector <int> y2, int q) {
			ans.clear();
			memset(dp, 0, sizeof(dp));
			dp[0] = 1;
			for (int i = 1; i <= q; ++i) {
				if (i == 1) {
					dp[i] = 2;
				} else {
					ll cnt = 0;
					for (int j = 0; j < i - 1; ++j) {
						if (insc(x1[j], y1[j], x2[j], y2[j], x1[i-1], y1[i-1], x2[i-1], y2[i-1])) {
							cnt++;
						}
					}
					dp[i] = dp[i-1] + cnt+1;
				}
				ans.push_back(dp[i]);
			}
			return ans;
		}
};
