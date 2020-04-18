#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define N 52
using namespace std;
typedef long long ll;
class Stamp {
public:
	int dp[N][3];
	int n;
	int getMinimumCost(string dc, int sc, int pc) {
		n = dc.size();
		int ans=1000000000;
		for (int len = 1; len <= n; ++len) {
			for (int i = 0; i <= n; ++i) {
				for (int j = 0; j < 3; ++j) {
					dp[i][j] = 1000000000;
				}
			}
			dp[0][0] = 0;
			dp[0][1]= 0;
			dp[0][2] = 0;
			vector<int>cnt={0,0,0};
			for (int i = 1; i <= n; ++i) {
				if (dc[i-1]=='R') cnt[0]++;
				if (dc[i-1]=='G') cnt[1]++;
				if (dc[i-1]=='B') cnt[2]++;
				if (i > len) {
					if (dc[i-len-1]=='R') cnt[0]--;
					if (dc[i-len-1]=='G') cnt[1]--;
					if (dc[i-len-1]=='B') cnt[2]--;
				}
				int num=(cnt[0]>0)+(cnt[1]>0)+(cnt[2]>0);
				if (i>=len && num<=1) {
					if (num==0) {
						for (int j = i-1; j> i-len; --j) {
							for (int c = 0; c < 3; ++c) {
								dp[i][c] = min(dp[i][c], dp[j][c]+pc);
							}
						}
						for (int c = 0;c < 3; ++c) {
							for (int c2 = 0; c2 < 3; ++c2) {
								dp[i][c] = min(dp[i][c], dp[i-len][c2]+pc);
							}
						}
					} else {
						int c = (cnt[0]>0 ? 0 : (cnt[1]>0 ? 1:  2));
						for (int j = i-1; j > i-len; --j) {
							dp[i][c] = min(dp[i][c], dp[j][c]+pc);
						}
						for (int c2 = 0;c2 < 3; ++c2) {
							dp[i][c] = min(dp[i][c], dp[i-len][c2]+pc);
						}
					}
				}
			}
			int cur = min(dp[n][0], min(dp[n][1], dp[n][2]));
			ans = min(ans, sc*len+cur);
		}
		return ans;
	}
};
