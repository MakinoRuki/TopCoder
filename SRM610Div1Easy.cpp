#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 102
using namespace std;
class TheMatrix {
	public:
		int n, m;
		int sum[N];
		int MaxArea(vector <string> board) {
			n = board.size();
			m = board[0].size();
			int ans = 0;
			for (int i = 0; i < n; ++i) {
				memset(sum, 0, sizeof(sum));
				for (int j = i; j < n; ++j) {
					for (int k = 0; k < m; ++k) {
						if (j == i) sum[k]++;
						else {
							if (sum[k]) {
								if (board[j - 1][k] != board[j][k]) sum[k]++;
								else sum[k] = 0;
							}
						}
					}
					int cnt = 0;
					for (int k = 0; k < m; ++k) {
						if (sum[k]) {
							if (cnt > 0) {
								if (board[i][k - 1] != board[i][k]) cnt++;
								else cnt = 1;
							} else {
								cnt++;
							}
						} else {
							cnt = 0;
						}
						ans = max(ans, cnt * (j - i + 1));
					//	if (ans == 3) cout<<i<<" "<<j<<" "<<k<<" "<<cnt<<endl;
					}
				}
			}
			return ans;
		}
};
