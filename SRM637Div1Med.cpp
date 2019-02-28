#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 1002
using namespace std;
class PathGame {
public:
	int n;
	int dp[N][3][3];
	bool check (int i, int j, int k, int l, int r) {
		if (j > 1 && j < i) {
			return true;
		}
		if (j == 1) {
			if ((k == 1 && l == 2) || (k == 2 && l == 1)) {
				return false;
			}
		} else {
			if ((k == 1 && r == 2) || (k == 2 && r == 1)) {
				return false;
			}
		}
		return true;
	}
	string judge (vector<string> board) {
		n = board[0].size();
		for (int i = 1; i <= 3; ++i) {
			for (int j = 1; j <= 3; ++j) {
				if ((i == 1 && j == 2) || (i == 2 && j == 1)) {
					dp[1][i][j] = 0;
				} else {
					dp[1][i][j] = 1;
				}
			}
		}
		for (int i = 2; i <= n; ++i) {
			for (int l = 1; l <= 3; ++l) {
				for (int r = 1; r <= 3; ++r) {
					bool mex[2 * N] = {0};
					for (int j = 1; j <= i; ++j) {
						for (int k = 1; k <= 2; ++k) {
							int tmp = 0;
							if (!check(i, j, k, l, r)) {
								continue;
							}
							if (j > 1) {
								tmp ^= dp[j - 1][l][k];
							}
							if (j < i) {
								tmp ^= dp[i - j][k][r];
							}
					//		if (i == 3 && l == 1 && r == 3 && tmp == 0)cout<<j<<" "<<k<<endl;
							mex[tmp] = true;
						}
					}
					for (int j = 0; j <= 2001; ++j) {
						if (!mex[j]) {
							dp[i][l][r] = j;
							break;
						}
					}
				}
			}
		}
		int ans = 0;
		int l = 3, cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (board[0][i] == '.' && board[1][i] == '.') {
				cnt++;
			} else {
				if (cnt > 0) {
					if (board[0][i] == '.') {
						ans ^= dp[cnt][l][2];
					} else {
						ans ^= dp[cnt][l][1];
					}
				//	cout<<cnt<<" "<<l<<" "<<ans<<endl;
				}
				cnt = 0;
				if (board[0][i] == '.') {
					l = 2;
				} else {
					l = 1;
				}
			}
		}
		if (cnt > 0) {
			if (board[0][n - 1] == '.' && board[1][n - 1] == '.') {
				ans ^= dp[cnt][l][3];
			//	cout<<cnt<<" "<<l<<" "<<dp[cnt][l][3]<<endl;
			} else {
				if (board[0][n - 1] == '.') {
					ans ^= dp[cnt][l][2];
				} else {
					ans ^= dp[cnt][l][1];
				}
			}
		}
		return (ans ? "Snuke" : "Sothe");
	}
};
