#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class TopXorer {
	public:
		int maximalRating (vector<int> x) {
			int n = x.size();
			sort(x.begin(), x.end());
			ll ans = 0;
			for (int i = n - 1; i >= 0; --i) {
				vector<int> bits;
				bits.clear();
				int y = x[i];
				while(y) {
					bits.push_back(y % 2);
					y /= 2;
				}
				bool ok = false;
				for (int j = bits.size() - 1; j >= 0; --j) {
					if (bits[j]) {
						if ((1<<j) & ans) {
							ok = true;
						} else {
							ans |= (1<<j);
						}
					} else {
						if (ok) {
							if (!((1<<j) & ans)) {
								ans |= (1<<j);
							}
						}
					}
				}
			}
			return ans;
		}
};
