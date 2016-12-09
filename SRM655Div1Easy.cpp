#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 30
using namespace std;
class BichromePainting {
	public:
		bool ok[N][N];
		int n;
		string isThatPossible (vector<string> board, int k) {
			n = board.size();
			memset(ok, false, sizeof(ok));
			while (true) {
				bool find = false;
				int i, j;
				for (i = 0; i + k <= n; ++i) {
					for (j = 0; j + k <= n; ++j) {
						int cnt = 0;
						int black = 0, white = 0;
						for (int r = 0; r < k; ++r) {
							for (int c = 0; c < k; ++c) {
								if (ok[i + r][j + c]) {
									cnt++;
								} else {
									if (board[i + r][j + c] == 'B') {
										black++;
									} else{
										white++;
									}
								}
							}
						}
						if (cnt == k * k) continue;
						if (cnt + black == k * k || cnt + white == k * k) {
							find = true;
							break;
						}
					}
					if (find) break;
				}
				for (int r = 0; r < k; ++r) {
					for (int c = 0; c < k; ++c) {
						ok[i + r][j + c] = true;
					}
				}
				if (!find) break;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (!ok[i][j]) return "Impossible";
				}
			}
			return "Possible";
		}
};
