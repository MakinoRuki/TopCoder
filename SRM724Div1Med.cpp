#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
class GravityPuzzle {
	public:
		int n, m;
		int col[N], row[N];
		int colcnt[N], rowcnt[N];
		ll comb[N][N];
		int count(vector<string> board) {
			n = board.size();
			m = board[0].size();
			memset(col, 0, sizeof(col));
			memset(row, 0, sizeof(row));
			ll ans = 0LL;
			ll res = 1LL;
			memset(comb, 0LL, sizeof(comb));
			for (int i = 0; i <= max(n, m); ++i) {
				comb[i][0] = 1LL;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
				}
			}
			bool up = true, down = true, left = true, right = true;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (board[i][j] == '#') {
						if (i > 0 && board[i - 1][j] == '.') up = false;
						if (i < n - 1 && board[i + 1][j] == '.') down = false;
						if (j > 0 && board[i][j - 1] == '.') left = false;
						if (j < m - 1 && board[i][j + 1] == '.') right = false;
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				int sum = 0;
				for (int j = 0; j < m; ++j) {
					sum += (board[i][j] == '#');
				}
				rowcnt[i] = sum;
				row[sum]++;
			}
			for (int j = 0; j < m; ++j) {
				int sum = 0;
				for (int i = 0; i < n; ++i) {
					sum += (board[i][j] == '#');
				}
				colcnt[j] = sum;
				col[sum]++;
			}
			if (!up && !down && !left && !right) return 1;
			ll tmpans = 1LL;
			if (up || down) {
				tmpans = 1LL;
				for (int j = 0; j < m; ++j) {
					tmpans = (tmpans * comb[n][colcnt[j]]) % mod;
				}
				if (left || right) {
					int tm = m;
					for (int j = 1; j <= n; ++j) {
						tmpans = (tmpans * comb[tm][col[j]]) % mod;
						res = res * comb[tm][col[j]] % mod;
						tm -= col[j];
					}
				}
				ans = (ans + tmpans) % mod;
			}
			if (left || right) {
				tmpans = 1LL;
				for (int i = 0; i < n; ++i) {
					tmpans = tmpans * comb[m][rowcnt[i]] % mod;
				}
				if (up || down) {
					int tn = n;
					for (int i = 1; i <= m; ++i) {
						tmpans = tmpans * comb[tn][row[i]] % mod;
						res = res * comb[tn][row[i]] % mod;
						tn -= row[i];
					}
				}
				ans = (ans + tmpans) % mod;
			}
			if ((up || down) && (left || right)) {
				ans = (ans - res + mod) % mod;
			}
			return ans;
		}
};
