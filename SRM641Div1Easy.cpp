#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 2502
using namespace std;
typedef long long ll;
struct pt {
	int x, y;
	pt(int x, int y): x(x), y(y) {}
	int quad () const {
		if (x > 0 && y >= 0) return 1;
		if (x <= 0 && y > 0) return 2;
		if (x < 0 && y <= 0) return 3;
		if (x >= 0 && y < 0) return 4;
		return 1; 
	}
	bool operator < (const pt & other) const {
		if (quad() == other.quad()) {	
			return x * other.y > y * other.x;
		} 
		return quad() < other.quad();
	}
};
class TrianglesContainOrigin {
	public:
		int n;
		vector<pt> points;
		ll getCnt (pt & a, pt & b) {
			if (a.x * b.y < b.x * a.y) {
				return 0LL;
			}
			int inx1 = upper_bound(points.begin(), points.end(), pt(-a.x, -a.y)) - points.begin();
			int inx2 = upper_bound(points.begin(), points.end(), pt(-b.x, -b.y)) - points.begin();
			if (inx1 <= inx2) {
				return inx2 - inx1;
			}
			return n - (inx1 - inx2);
		}
		ll count (vector<int> x, vector<int> y) {
			n = x.size();
			for (int i = 0; i < n; ++i) {
				points.push_back(pt(x[i], y[i]));
			}
			sort(points.begin(), points.end());
		//	for (int i = 0; i < n; ++i)cout<<points[i].x<<" "<<points[i].y<<endl;
			ll ans = 0LL;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
                    if (getCnt(points[i], points[j])) {
          //             cout<<i<<" "<<j<<" "<<getCnt(points[i], points[j])<<endl;
                    }
					ans += getCnt(points[i], points[j]);
				}
			}
			return ans / 3LL;
		}
};
