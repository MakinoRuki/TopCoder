#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
class SubdividedSlimes {
	public:
		map<int, int> cnt;
		int needCut (int S, int M) {
			for (int i = 1; i < S; ++i) {
				int t = i + 1;
				int ans = 0;
				for (int j = 1; j <= t - S % t; ++j) {
					ans += (S / t) * (S / t);
				}
				for (int j = 1; j <= S % t; ++j) {
					ans += (S / t + 1) * (S / t + 1);
				}
				ans = (S * S - ans) / 2;
				if (ans >= M) return i;
			}
			return -1;
		}
};
