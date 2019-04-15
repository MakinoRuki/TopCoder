#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 5005
using namespace std;
typedef long long ll;
class OneDimensionalRobot {
	public:
		int ans[N][N];
		int n;
		ll theSum(vector<string> c1, vector<string> c2, int minA, int maxA, int minB, int maxB) {
			int L = 0, R = 0;
			int s = 0;
			string c = "";
			for (int i = 0; i < c1.size(); ++i) {
				c += c1[i];
			}
			for (int i = 0; i < c2.size(); ++i) {
				c += c2[i];
			}
			n = c.size();
			for (int i = 0; i < n; ++i) {
				s += (c[i] == 'L' ? -1 : 1);
				L = max(L, -s);
				R = max(R, s);
			}
			ll tot = 0;
			for (int a = minA; a <= maxA; ++a) {
				for (int b = maxB; b >= minB; --b) {
					if (a-1 >= minA && a <= maxA && b + 1 >= minB && b + 1 <= maxB) {
						ans[a][b] = ans[a-1][b+1];
						if (L > a - 1 || R > b) {
							ans[a][b]--;
						}
					} else if (L <= a && R <= b) {
						ans[a][b] = s;
					} else {
						int s2 = 0;
						for (int i = 0; i < n; ++i) {
							s2 += (c[i] == 'L' ? -1 : 1);
							s2 = max(-a, s2);
							s2 = min(b, s2);
						}
						ans[a][b] = s2;
					}
					tot += ans[a][b];
				}
			}
			return tot;
		}
};
