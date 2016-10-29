#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class PartisanGame {
	public:
		bool win[100000][2];
		int idx[2000];
		string getWinner (int n, vector<int> a, vector<int> b) {
			memset(win, false, sizeof(win));
			memset(idx, -1, sizeof(idx));
			for (int i = 1; i <= n; ++i) {
				bool res = true;
				for (int j = 0; j < a.size(); ++j) {
					if (i >= a[j]) {
						res &= win[i - a[j]][1];
					}
				}
				win[i][0] = !res;
				res = true;
				for (int j = 0; j < b.size(); ++j) {
					if (i >= b[j]) {
						res &= win[i - b[j]][0];
					}
				}
				win[i][1] = !res;
				if (i > 100) {
					int pre = 0;
					// 结果只与前5个数相关,因此是2^10个状态。
					for (int j = 1; j <= 5; ++j) {
						pre = pre * 2 + win[i - j][0];
						pre = pre * 2 + win[i - j][1];
					}
					if (idx[pre] >= 0) {
						int cycle = i - idx[pre];
						int number = (n - idx[pre]) / cycle;
						number--;
						n -= number * cycle;
					} else {
						idx[pre] = i;
					}
				}	
			}
			return win[n][0] ? "Alice" : "Bob";
		}
};
