#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 52
using namespace std;
class MakeSquare {
	public:
		int n;
		int dp[N][N];
		int solve(string a, string b) {
			int la = a.size();
			int lb = b.size();
			for (int i = 0; i <= la; ++i) {
				for (int j = 0; j <= lb; ++j) {
					dp[i][j] = 1000000000;
				}
			}
			dp[0][0] = 0;
			for (int j = 1; j <= lb; ++j) {
				dp[0][j] = j;
			}
			for (int i = 1; i <= la; ++i) {
				dp[i][0] = i;
			}
			for (int i = 1; i <= la; ++i) {
				for (int j = 1; j <= lb; ++j) {
					dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
					dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1]!=b[j-1]));
				}
			}
			return dp[la][lb];
		}
		int minChanges(string s) {
			n = s.size();
			int ans= n;
			for (int i = 1; i < n; ++i) {
				ans = min(ans, solve(s.substr(0, i), s.substr(i)));
			}
			return ans;
		}
};
