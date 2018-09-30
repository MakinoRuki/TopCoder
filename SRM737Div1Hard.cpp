#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class Make737Hard {
	public:
		string make(int x) {
			string ans;
			for (int side = 1; ;++side) {
				ll mid = (x + side * side - 1) / (side * side);
				if (side + mid + side > 373) continue;
				ans = string(side, '7') + string(mid, '3') + string(side, '7');
				ll cur = mid * side * side;
				for (int i = side; i < side + mid; ++i) {
					for (int j = 1; j <= side; ++j) {
						ll det = 2 * j - 1;
						if (cur - det >= x) {
							cur -= det;
							swap(ans[i - j], ans[i - j + 1]);
						}
					}
				}
				if (cur == x) return ans;
			}
			return ans;
		}
};
