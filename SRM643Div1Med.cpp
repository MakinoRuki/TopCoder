#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
class TheKingsArmyDiv1 {
	public:
		int n;
		int getNumber (vector<string> state) {
			n = state[0].size();
			int pre = -1;
			int ans = 0;
			int up = 0, down = 0;
			for (int i = 0; i < n; ++i) {
				if ((state[0][i] == state[1][i]) && (state[0][i] == 'S')) {
					ans++;
				}
				if (state[0][i] != state[1][i]) {
					int now = state[0][i] == 'S';
					if (now != pre) {
						if (now) up++;
						else down++;
						pre = now;
					}
				}
			}
		//	return ans;
			if (ans == n) return -1;
			if (pre >= 0) {
				ans += min(up, down) + 1;
			}
			return ans;
		}
};
