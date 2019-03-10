#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 2002
using namespace std;
class ReconstructNumber {
	public:
		int n;
		bool can[N][10];
		string smallest(string cs) {
			n = cs.size();
			memset(can, false, sizeof(can));
			if (n == 0) return "1";
			for (int i = 0; i < 10; ++i) {
				can[n][i] = true;
			}
			for (int i = n - 1; i >= 0; --i) {
				for (int j = 0; j < 10; ++j) {
					for (int k = 0; k < 10; ++k) {
						if (!can[i + 1][k]) continue;
						if (cs[i] == '<' && j < k) can[i][j] = true;
						if (cs[i] == '>' && j > k) can[i][j] = true;
						if (cs[i] == '=' && j == k) can[i][j] = true;
						if (cs[i] == '!' && j != k) can[i][j] = true;
					}
				}
			}
			string ans = "";
			int d;
			for (d = 1; d < 10; ++d) {
				if (can[0][d]) break;
			}
			if (d >= 10) return "";
			ans += '0' + d;
			for (int i = 1; i <= n; ++i) {
				int j;
				for (j = 0; j < 10; ++j) {
					if (!can[i][j]) continue;
					if (cs[i - 1] == '<' && d < j) break;
					if (cs[i - 1] == '>' && d > j) break;
					if (cs[i - 1] == '=' && d == j) break;
					if (cs[i - 1] == '!' && d != j) break;
				}
				ans += '0' + j;
				d = j;
			}
			return ans;
		}
};
