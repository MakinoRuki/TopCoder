#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
const int mod = 1000000007;
class Newgenerations {
	public:
		int n, m;
		int idx[N][N];
		int cnt;
		int dp[2][1<<20];
		bool inact(int i, int j, vector<string>& field) {
			if (i < 0 || i >= n || j < 0 || j >= m) return true;
			if (field[i][j] == '.') return true;
			return false;
		}
		bool check(int i, int j) {
			if (i < 0 || i >= n || j < 0 || j >= m) return false;
			if (idx[i][j] < 0) return false;
			return true;
		}
		int count(vector<string> field) {
			n = field.size();
			m = field[0].size();
			memset(idx, -1, sizeof(idx));
			cnt = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (field[i][j] == 'x') {
						if (inact(i - 1, j, field) || inact(i+1, j, field) || inact(i, j-1, field) || inact(i, j + 1, field)) {
							continue;
						}
						idx[i][j] = cnt++;
					}
				}
			}
			vector<int> masks;
			masks.clear();
			int free = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					if (field[i][j] == '*') {
						int st = 0;
						if (check(i-1, j)) st |= (1<<idx[i-1][j]);
						if (check(i+1, j)) st |= (1<<idx[i+1][j]);
						if (check(i, j-1)) st |= (1<<idx[i][j-1]);
						if (check(i, j+1)) st |= (1<<idx[i][j+1]);
						if (st) masks.push_back(st);
						else free++;
					}
				}
			}
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;
			for (int i = 0; i < masks.size(); ++i) {
				int now = ((i&1)^1);
				memset(dp[now], 0, sizeof(dp[now]));
				for (int j = 0; j < (1<<cnt); ++j) {
					dp[now][j] += dp[i&1][j];
					if (dp[now][j] > mod) dp[now][j] -= mod;
					int nj = j | masks[i];
					dp[now][nj] += dp[i&1][j];
					if (dp[now][nj] > mod) dp[now][nj] -= mod;
				}
			}
			int ans = dp[masks.size() & 1][(1<<cnt) - 1];
			for (int i = 1; i <= free; ++i) {
				ans *= 2;
				if (ans > mod) ans -= mod;
			}
			return ans;
		}
};
