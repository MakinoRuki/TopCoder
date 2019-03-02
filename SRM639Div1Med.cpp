#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define NN 252
using namespace std;
typedef long long ll;
class BoardFolding {
	public:
		vector<vector<int> > paper;
		bool rowValid[NN][NN], colValid[NN][NN];
		ll ans;
		ll rowNum, colNum;
		int tonumber (char ch) {
			if (ch >= '0' && ch <= '9') return ch - '0';
			if (ch >= 'a' && ch <= 'z') return ch - 'a' + 10;
			if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 36;
			if (ch == '#') return 62;
			if (ch == '@') return 63;
			return 64;
		}
		void calRow (int N, int M) {
			memset(rowValid, false, sizeof(rowValid));
			for (int i = N - 1; i >= 0; --i) {
				for (int j = i; j < N; ++j) {
					if (j == i) rowValid[i][j] = true;
					if ((j - i + 1) & 1)continue;
					int k;
					for (k = 0; k < M; ++k) {
						if (paper[i][k] != paper[j][k]) {
							break;
						}
					}
					if (i == 0 && j == 1)cerr<<"k "<<paper[0][1]<<" "<<paper[1][1]<<endl;
					rowValid[i][j] = (k >= M);
					if (j > i + 1) {
						rowValid[i][j] &= rowValid[i + 1][j - 1];
					} 
				}
			}
		}
		void calCol (int N, int M) {
			memset(colValid, false, sizeof(colValid));
			for (int i = M - 1; i >= 0; --i) {
				for (int j = i; j < M; ++j) {
					if (j == i) colValid[i][j] = true;
					if ((j - i + 1) & 1) continue;
					int k;
					for (k = 0; k < N; ++k) {
						if (paper[k][i] != paper[k][j]) {
							break;
						}
					}
					colValid[i][j] = (k >= N);
					if (j > i + 1) {
						colValid[i][j] &= colValid[i + 1][j - 1];
					} 
				}
			}
		}
		ll solveRow (int N) {
			bool ok[NN][NN];
			memset(ok, false, sizeof(ok));
			ok[0][N - 1] = true;
			ll res = 0LL;
			for (int i = 0; i < N; ++i) {
				for (int j = N - 1; j >= i; --j) {
					for (int k = 0; k < i; ++k) {
						if (ok[k][j] && 2 * i - k - 1 <= j && rowValid[k][2 * i - k - 1]) {
							ok[i][j] = true;
							break;
						}
					}
					for (int k = j + 1; k < N; ++k) {
						if (ok[i][k] && 2 * j - k + 1 >= i && rowValid[2 * j - k + 1][k]) {
							ok[i][j] = true;
							break;
						}
					}
					if (ok[i][j]) res++;
				}
			} 
			return res;
		}
		ll solveCol (int M) {
			bool ok[NN][NN];
			memset(ok, false, sizeof(ok));
			ok[0][M - 1] = true;
			ll res = 0LL;
			for (int i = 0; i < M; ++i) {
				for (int j = M - 1; j >= i; --j) {
					for (int k = 0; k < i; ++k) {
						if (ok[k][j] && 2 * i - k - 1 <= j && colValid[k][2 * i - k - 1]) {
							ok[i][j] = true;
							break;
						}
					}
					for (int k = j + 1; k < M; ++k) {
						if (ok[i][k] && 2 * j - k + 1 >= i && colValid[2 * j - k + 1][k]) {
							ok[i][j] = true;
							break;
						}
					}
					if (ok[i][j]) res++;
				}
			} 
			return res;
		}
		int howMany (int N, int M, vector<string> compressedPaper) {
			vector<int> tmp;
			tmp.clear();
			for (int i = 0; i < N; ++i) {
				tmp.clear();
				for (int j = 0; j < M; ++j) {
					tmp.push_back((tonumber(compressedPaper[i][j / 6]) >> (j % 6)) % 2);
				}
				paper.push_back(tmp);
			}
			M = paper[0].size();
			calRow(N, M);
			calCol(N, M);
			cerr<<rowValid[0][1]<<endl;
			ans = 1LL;
			ans *= solveRow(N);
		//	return ans;
			ans *= solveCol(M);
			return ans;
		}
};
