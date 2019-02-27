#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 402
using namespace std;
typedef pair<int, int> point;
class ClosestRabbit {
	public:
		vector<point> inx;
		double comb[N][N];
		int h,w,n;
		double ans;
		void getComb () {
			for (int i = 0; i <= n; ++i) {
				comb[i][0] = 1.0;
				for (int j = 1; j <= i; ++j) {
					comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
				}
			}
		}
		int getDis (point & a, point & b) {
			return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
		}
		bool getOrder (point & a, point & b) {
			if (a.first == b.first) {
				return a.second < b.second;
			}
			return a.first < b.first;
		}
		bool check (point & a, point & b, point & c) {
			if (getDis(a, c) == getDis(a, b)) {
				return getOrder(b, c);
			} else {
				return getDis(a, c) > getDis(a, b);
			}
		}
		double getExpected (vector<string> board, int r) {
			h = board.size();
			w = board[0].size();
			inx.clear();
			for (int i = 0; i < h; ++i) {
				for (int j = 0; j < w; ++j) {
					if (board[i][j] == '.') {
						inx.push_back(make_pair(i, j));
					}
				}
			}
			n = inx.size();
			getComb();
			ans = 0.0;
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					int others = 0;
					for (int k = 0; k < n; ++k) {
						if (k != i && k != j) {
							if (check(inx[i], inx[j], inx[k]) && check(inx[j], inx[i], inx[k])) {
								others++;
							}
						}
					}
					ans += comb[others][r - 2] / comb[n][r];
				}
			}
			return ans;
		}
};
