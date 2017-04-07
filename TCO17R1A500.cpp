#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define pii pair<int, int>
#define piii pair<pii, int>
#define mp make_pair
using namespace std;
class CheeseSlicing {
	public:
		int totalArea (int A, int B, int C, int s) {
			queue<piii> Q;
			Q.push(mp(mp(A, B), C));
			int ans = 0;
			int a, b, c;
			while (!Q.empty()) {
				piii cur = Q.front();
				Q.pop();
				vector<int> tmp;
				a = cur.first.first;
				b = cur.first.second;
				c = cur.second;
				tmp.push_back(a);
				tmp.push_back(b);
				tmp.push_back(c);
				sort(tmp.begin(), tmp.end());
				a = tmp[2];
				b = tmp[1];
				c = tmp[0];
				if (c < s) return 0;
				if (2 * s > a) {
					ans += a * b;
				} else {
					int q = a / s;
					if (a % s) q--;
					for (int i = 1; i <= q; ++i) {
						Q.push(mp(mp(b, c), s));
					}
					if (a % s) {
						Q.push(mp(mp(b, c), a - q * s));
					}
				}
			}
			return ans;
		}
};
