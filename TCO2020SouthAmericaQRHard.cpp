#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 1002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
class LetterS {
	public:
		bool mat[N][N];
		ll dp[N][N][4];
		int count(int r, int c, vector<int> obr, vector<int> obc) {
			memset(mat, false, sizeof(mat));
			int m = obr.size();
			for (int i = 0; i < m; ++i) {
				mat[obr[i]][obc[i]]=true;
			}
			memset(dp, 0LL, sizeof(dp));
			for (int i = 0; i < r; ++i) {
				for (int j = 1; j < c; ++j) {
					if (!mat[i][j] && !mat[i][j-1]) {
						dp[i][j][0]=(dp[i][j-1][0]+1)%mod;
					}
				}
				for (int j = c-2; j >= 0; --j) {
					if (!mat[i][j] && !mat[i][j+1]) {
						dp[i][j][1] = (dp[i][j+1][1]+1)%mod;
					}
				}
			}
			for (int j = 0; j < c; ++j) {
				for (int i = 2; i < r; ++i) {
					if (!mat[i][j] && !mat[i-1][j] && !mat[i-2][j]) {
						dp[i][j][2] = (dp[i-1][j][2]+dp[i][j][2])%mod;
						dp[i][j][2] = (dp[i][j][2] + dp[i-2][j][1])%mod;
					}
				}
				for (int i = r-3; i >= 0; --i) {
					if (!mat[i][j] && !mat[i+1][j] && !mat[i+2][j]) {
						dp[i][j][3] = (dp[i][j][3]+dp[i+1][j][3])%mod;
						dp[i][j][3] = (dp[i][j][3] + dp[i+2][j][0])%mod;
					}
				}
			}
			ll ans=0LL;
			for (int i = 0; i < r; ++i) {
				ll pre=0LL;
				for (int j = 0; j < c; ++j) {
					if (mat[i][j]) pre=0LL;
					else {
						ans = (ans+pre*dp[i][j][3]%mod)%mod;
						pre = (pre+dp[i][j][2])%mod;
					}
				}
			}
			return ans;
		}
};
