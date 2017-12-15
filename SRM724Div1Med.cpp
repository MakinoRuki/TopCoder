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
			ll ans = 1LL;
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
			ll res = 1LL;
			if (up || down) {
				for (int j = 0; j <= n; ++j) {
					if (col[j]) {
						ans = ans * comb[m][col[j]] % mod;
						res = res * comb[m][col[j]] % mod;
					}
				}
				for (int j = 0; j < m; ++j) {
					ans = ans * comb[n][colcnt[j]] % mod;
				}
			}
			if (left || right) {
				for (int i = 0; i <= m; ++i) {
					if (row[i]) {
						ans = ans * comb[n][row[i]] % mod;
						res = res * comb[n][row[i]] % mod;
					}
				}
				for (int i = 0; i < n; ++i) {
					ans = ans * comb[m][rowcnt[i]] % mod;
				}
			}
			if ((left || right) && (up || down)) {
				ans = (ans - res + mod) % mod;
			}
			return ans;
		}
};
