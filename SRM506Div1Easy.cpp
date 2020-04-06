#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#define N 102
using namespace std;
typedef long long ll;
class SlimeXSlimesCity {
	public:
		int merge(vector<int> ps) {
			int n = ps.size();
			sort(ps.begin(), ps.end());
			int cnt=0;
			for (int i = 0; i < n; ++i) {
				ll cur = ps[i];
				int j;
				for (j = 0; j < n; ++j) {
					if (j == i) continue;
					if (cur >= ps[j]) {
						cur += ps[j];
					} else {
						break;
					}
				}
				if (j >= n) cnt++;
			}
			return cnt;
		}
};
