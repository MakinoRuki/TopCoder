#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Saleswoman {
	public:
		int n;
		int minMoves (vector<int> pos, vector<int> delta) {
			n = pos.size();
			int ans = 0;
			int have = 0, demand = 0;
			int idx = -1;
			for (int i = 0; i < n; ++i) {
				if (delta[i] >= 0) {
					have += delta[i];
					if (have >= -demand && idx >= 0) {
						ans += (pos[i] - pos[idx]) * 2;
						have += demand;
						demand = 0;
						idx = -1;
					}
				} else {
					demand += delta[i];
					if (-demand > have) {
						if (idx < 0) idx = i;
					} else {
						have += demand;
						demand = 0;
						idx = -1;
					}
				}
				if (i == 0) ans += pos[i];
				else ans += pos[i] - pos[i - 1];
			}
			return ans;
		}
};
