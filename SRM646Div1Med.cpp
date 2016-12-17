#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 500
#define mp make_pair
using namespace std;
class TheGridDivOne {
	public:
		int dis[N][N];
		int n, m;
		int find (vector<int> x, vector<int> y, int k) {
			set<int> sx, sy;
			set<pair<int, int> > blocks;
			for (int i = 0; i < x.size(); ++i) {
				blocks.insert(mp(x[i], y[i]));
			}
			for (int i = 0; i < x.size(); ++i) {
				for (int d = -1; d <= 1; ++d) {
					sx.insert(x[i] + d);
				}
			}
			for (int i = 0; i < y.size(); ++i) {
				for (int d = -1; d <= 1; ++d) {
					sy.insert(y[i] + d);
				}
			}
			sx.insert(0);
			sy.insert(0);
			vector<int> vx(sx.begin(), sx.end());
			vector<int> vy(sy.begin(), sy.end());
			n = vx.size(), m = vy.size();
			set<pair<int, pair<int, int> > > Q;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					dis[i][j] = k + 1;
					if (vx[i] == 0 && vy[j] == 0) {
						dis[i][j] = 0;
						Q.insert(mp(0, mp(i, j)));
					}
				}
			}
			int ans = 0;
			for (auto itr = Q.begin(); itr != Q.end(); ++itr) {
				int d = itr->first;
				int x = itr->second.first;
				int y = itr->second.second;
		//		cout<<"w"<<" "<<vx[x]<<" "<<vy[y]<<endl;
				int w = vx[x] + k - d;
				if (x + 1 < n) {
					w = min(w, vx[x + 1] - 1);
				}
				ans = max(ans, w);
				for (int i = max(0, x - 1); i <= min(n - 1, x + 1); ++i) {
					for (int j = max(0, y - 1); j <= min(m - 1, y + 1); ++j) {
						if (blocks.find(mp(vx[i], vy[j])) == blocks.end()) {
							if (vx[i] == vx[x] || vy[j] == vy[y]) {
								int delta = abs(vx[i] - vx[x]) + abs(vy[j] - vy[y]);
								if (d + delta < dis[i][j]) {
			//						cout<<vx[i]<<" "<<vy[j]<<endl;
									Q.erase(mp(dis[i][j], mp(i, j)));
									dis[i][j] = d + delta;
									Q.insert(mp(dis[i][j], mp(i, j)));
								}
							}
						}
					}
				}
			}
			return ans;
		}
};
