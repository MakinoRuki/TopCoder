// 对比原先错误的做法。
// 1）扫描线并无法找出任意相交的k个线段。
// 反例：{{1,1,1,1,1},{1,10,9,19,11},{2,2,2,2,2},{20,30,12,21,13},2}
// 2）本题对于y这一维上，其实还是在枚举。枚举yl的最大值YL，然后对于当前已枚举的所有yl[i]<=YL，需要找出yh[i]最大的k个。
// yl推进的时候，始终维护这样的k个yh。

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
class KRectangleIntersection {
	public:
		ll maxIntersection(vector<int> xl, vector<int> yl, vector<int> xh, vector<int> yh, int k) {
			set<int> xs;
			xs.clear();
			int n = xl.size();
			for (int i = 0; i < n; ++i) {
				xs.insert(xl[i]);
				xs.insert(xh[i]);
			}
			vector<int> xv(xs.begin(), xs.end());
		//	int m = xv.size();
			ll ans = 0LL;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					int x1 = xl[i];
					int x2 = xh[j];
					if (x1 > x2) continue;
					ll dx = x2 - x1;
				//	vector<pair<pair<int, int>, int>> rks;
					// rks.clear();
					// for (int a = 0;a < n; ++a) {
					// 	if (xl[a] <= x1 && xh[a] >= x2) {
					// 		rks.push_back(make_pair(make_pair(yl[a], 1), a));
					// 		rks.push_back(make_pair(make_pair(yh[a], -1), a));
					// 	}
					// }
					vector<pair<int, int>> rks;
					rks.clear();
					for (int a = 0;a < n; ++a) {
						if (xl[a] <= x1 && xh[a] >= x2) {
							rks.push_back(make_pair(yl[a], yh[a]));
						}
					}
					sort(rks.begin(), rks.end());
				//	int cnt=0;
					// set<pair<int, int>> bs;
					// set<pair<int, int>> es;
					// bs.clear();
					// es.clear();
					// ll tot = 0;
					// for (int a = 0; a < rks.size(); ++a) {
					// //	int cy = rks[a].first.first;
					// 	int cf = rks[a].first.second;
					// 	int id = rks[a].second;
					// 	if (cf == 1) {
					// 		es.insert(make_pair(yh[id], id));
					// 		bs.insert(make_pair(yl[id], id));
					// 	} else {
					// 		es.erase(make_pair(yh[id], id));
					// 		bs.erase(make_pair(yl[id], id));
					// 	}
					// 	if (bs.size() == k) {
					// 		ll tmp = (*es.begin()).first - (*bs.rbegin()).first;
					// 		tot = max(tot, tmp);
					// 	}
					// }
					set<pair<int, int>> ss;
					ss.clear();
					ll tot =0;
					for (int a = 0; a < rks.size(); ++a) {
						ll y1 = rks[a].first;
						ss.insert(make_pair(rks[a].second, a));
						while(ss.size() > k) {
							ss.erase(*ss.begin());
						}
						if (ss.size() == k) {
							tot = max(tot, (*ss.begin()).first - y1);
						}
					}
				//	cout<<x1<<" "<<x2<<" "<<tot<<endl;
					ans = max(ans, dx * tot);
				}
			}
			return ans;
		}
};

// {{2, 5, 1}, {3, 7, 1}, {7, 10, 6}, {9, 10, 5}, 2} 8
// {{2, 5, 1}, {3, 7, 1}, {7, 10, 6}, {9, 10, 5}, 1} 30
// {{2, 5, 1}, {3, 7, 1}, {7, 10, 6}, {9, 10, 5}, 3} 0

// {{1, 1}, {1, 10}, {10, 10}, {10, 20}, 2} 0
// {{2, 5, 1}, {3, 7, 1}, {7, 10, 6}, {9, 10, 5}, 1} 30
// {{1, 2}, {2, 1}, {4, 3}, {3, 4}, 2} 1
// {{1, 1, 1, 1}, {1, 1, 1, 1}, {2, 2, 2, 2}, {2, 2, 2, 2}, 4} 1
// {{1, 3, 2}, {1, 2, 3}, {4, 6, 5}, {5, 4, 6}, 3} 1
// {{1, 2, 4}, {1, 2, 4}, {9, 3, 6}, {9, 3, 6}, 2} 4
// Args:
// {{1, 3}, {3, 1}, {4, 6}, {6, 4}, 2} 1
// {{1, 2, 2, 2, 5, 5}, {1, 1, 1, 2, 1, 6}, {3, 4, 3, 3, 9, 9}, {3, 3, 2, 3, 5, 10}, 2} 2
// {{1, 2, 3}, {3, 2, 1}, {6, 4, 5}, {6, 4, 5}, 3} 1
// {{1, 5, 7}, {1, 5, 2}, {10, 20, 12}, {10, 20, 8}, 3} 9

// {{1, 6, 1, 4, 4}, {1, 6, 1, 4, 4}, {2, 8, 5, 8, 5}, {2, 8, 5, 8, 5}, 3} 1
// {{1, 1, 1}, {1, 1, 3}, {2, 2, 2}, {6, 6, 7}, 2} 5
// {{1, 1, 1}, {1, 1, 1}, {2, 2, 2}, {2, 2, 2}, 2} 1

