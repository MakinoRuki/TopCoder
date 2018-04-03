#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class BrownieGame {
	public:
		int getres(int r, int c) {
			if (r == 1) return c - 1;
			if (c == 1) return -(r - 1);
			return getres(r / 2, c / 2);
		}
		vector<int> HowToCheat(int n, vector <int> r, vector <int> c) {
			ll tot = 0LL;
			for (int i = 0; i < n; ++i) {
				tot += (ll)getres(r[i], c[i]);
			}
			return {max(0LL, tot), max(0LL, tot + 1LL)};
		}
};
