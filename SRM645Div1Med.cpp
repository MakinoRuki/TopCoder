// 偶数次变换后,坐标之间的delta必然形如i * 2 * (A - B) + j * 2 * (A - C)。奇数次之后则可以先关于A/B/C对称一次,然后转化为偶数次的情况。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define mp make_pair
#define pii pair<int, int>
using namespace std;
typedef long long ll;
class ArmyTeleportation {
	public:
		int n;
		vector<pii> org, tar;
		bool solve (vector<int> & xt, vector<int> & yt) {
			int dtx = tar[0].first - org[0].first;
			int dty = tar[0].second - org[0].second;
			for (int i = 1; i < n; ++i) {
				if (dtx != tar[i].first - org[i].first) return false;
				if (dty != tar[i].second - org[i].second) return false;
			}
			int dtx1 = 2 * (xt[0] - xt[2]);
			int dty1 = 2 * (yt[0] - yt[2]);
			int dtx2 = 2 * (xt[1] - xt[2]);
			int dty2 = 2 * (yt[1] - yt[2]);
			ll w = (ll)dtx * (ll)dty2 - (ll)dty * (ll)dtx2;
			ll z = (ll)dtx * (ll)dty1 - (ll)dty * (ll)dtx1;
			ll q = (ll)dtx1 * (ll)dty2 - (ll)dtx2 * (ll)dty1;
			if (q != 0LL) {
				if ((w % q) || (z % q)) return false;
				return true;
			} 
			if (w || z) return false;
			ll d = __gcd(abs(dtx1), abs(dtx2));
			if (dtx % d) return false;
			return true;
		}
		string ifPossible (vector<int> x1, vector<int> y1, vector<int> x2, vector<int> y2, vector<int> xt, vector<int> yt) {
			org.clear();
			tar.clear();
			n = x1.size();
			for (int i = 0; i < n; ++i) {
				tar.push_back(mp(x2[i], y2[i]));
			}
			sort(tar.begin(), tar.end());
			for (int i = 0; i < 4; ++i) {
				org.clear();
				if (i == 0) {
					for (int j = 0; j < n; ++j) {
						org.push_back(mp(x1[j], y1[j]));
					}
				} else {
					int refx = 2 * xt[0], refy = 2 * yt[0];
					if (i == 2) refx = 2 * xt[1], refy = 2 * yt[1];
					if (i == 3) refx = 2 * xt[2], refy = 2 * yt[2];
					for (int j = 0; j < n; ++j) {
						org.push_back(mp(refx - x1[j], refy - y1[j]));
					}
				}
				sort(org.begin(), org.end());
				if (solve(xt, yt)) return "possible";
			}
			return "impossible";
		}
};
