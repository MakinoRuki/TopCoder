#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_set>
#define N 3010
using namespace std;
typedef long long ll;
class MoreSquares {
	public:
		int X[N], Y[N];
		int countLocations(int n, int sx, int sy, vector <int> xp, vector <int> yp) {
			unordered_set<ll> pts;
			pts.clear();
			for (int i = 0; i < xp.size(); ++i) {
				X[i] = xp[i];
				Y[i] = yp[i];
				pts.insert(X[i]*1000000LL+Y[i]);
			}
			for (int i = xp.size(); i < n; ++i) {
				X[i] = (X[i-1]*47+42)%sx;
				Y[i] = (Y[i-1]*47+42)%sy;
				pts.insert(X[i]*1000000LL+Y[i]);
			}
			unordered_set<int> ans;
			ans.clear();
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					int vx0 = X[j]-X[i];
					int vy0 = Y[j]-Y[i];
					int vx1 = vy0;
					int vy1 = -vx0;
					int vx2 = X[i]+vx1;
					int vy2 = Y[i]+vy1;
					bool f1 = (pts.find(vx2*1000000LL+vy2) != pts.end());
					int vx3 = X[j]+vx1;
					int vy3 = Y[j]+vy1;
					bool f2 = (pts.find(vx3*1000000LL+vy3) != pts.end());
					if (f1 != f2) {
						if (!f2) ans.insert(vx3*1000000LL+vy3);
						else ans.insert(vx2*1000000LL+vy2);
					}
					vx1 = -vy0;
					vy1 = vx0;
					vx2 = X[i]+vx1;
					vy2 = Y[i]+vy1;
					f1 = (pts.find(vx2*1000000LL+vy2) != pts.end());
					vx3 = X[j]+vx1;
					vy3 = Y[j]+vy1;
					f2 = (pts.find(vx3*1000000LL+vy3) != pts.end());
					if (f1 != f2) {
						if (!f2) ans.insert(vx3*1000000LL+vy3);
						else ans.insert(vx2*1000000LL+vy2);
					}
				}
			}
			return ans.size();
		}
};
