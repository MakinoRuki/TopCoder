#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 52
using namespace std;
class LightbulbGame {
	public:
		int sg[N][N];
		int countWinningMoves (vector<string> board) {
			int n = board.size();
			int m = board[0].size();
			for (int r = n - 1; r >= 0; --r) {
				for (int c = m - 1; c >= 0; --c) {
					set<int> s;
					s.insert(0);
					for (int j = c + 1; j < m; ++j) s.insert(sg[r][j]);
					for (int i = r + 1; i < n; ++i) s.insert(sg[i][c]);
					sg[r][c] = 0;
					while(s.find(sg[r][c]) != s.end()) sg[r][c]++;
				}
			}
			int tot = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (board[i][j] == '1') tot ^= sg[i][j];
				}
			}
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (board[i][j] == '1') {
						int tot2 = tot ^ sg[i][j];
						if (tot2 == 0) ans++;
						for (int i2 = i + 1; i2 < n; ++i2) if (tot2 == sg[i2][j]) ans++;
						for (int j2 = j + 1; j2 < m; ++j2) if (tot2 == sg[i][j2]) ans++;
					}
				}
			}
			return ans;
		}
};
