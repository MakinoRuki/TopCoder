#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define eps 1e-9
using namespace std;
typedef long long ll;
class FindThePerfectTriangle {
	public:
		vector<int> constructTriangle (int area, int peri) {
			vector<vector<int>> pts;
			pts.clear();
			for (int i = 0; i <= 500; ++i) {
				for (int j = 0; j <= 500; ++j) {
					int r = (int)sqrt(i * i + j * j);
					if (r <= 500 && r * r == i*i+j*j) {
						pts.push_back({i, j, r});
					}
				}
			}
			for (int i = 0; i < pts.size(); ++i) {
				for (int j = 0; j < pts.size(); ++j) {
					if (i == j) continue;
					if (pts[i][2] + pts[j][2] >= peri) continue;
					int x1 = pts[i][0];
					int y1 = pts[i][1];
					int x2 = pts[j][0];
					int y2 = pts[j][1];
					int d = (int)sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
					if ((d*d == (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) && (d+pts[i][2]+pts[j][2]==peri) && ((x1*y2-x2*y1) % 2 == 0) && (abs(x1*y2-x2*y1)/2==area)) {
						return {0, 0, x1, y1, x2, y2};
					}
				}
			}
			return {};
		}
};
