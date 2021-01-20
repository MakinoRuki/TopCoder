#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 1000005
using namespace std;
typedef long long ll;
class ChristmasBatteries {
	public:
		int dp[N][8];
		int mostFun(int b, int n, int x, int y, int z, int m) {
			memset(dp, -1, sizeof(dp));
			dp[0][0] = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j <= b; ++j) {
					if (dp[i][j]>=0) {
						int sz=i%5;
						ll v=((ll)x*(ll)i*(ll)i+(ll)y*(ll)i+(ll)z)%m;
					//	if (i==0&&b==0) cout<<sz<<" "<<v<<endl;
						dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
						if (j+sz<=b) {
							dp[i+1][j+sz] = max(dp[i+1][j+sz], dp[i][j]+(int)v);
						}
					}
				}
			}
		//	cout<<dp[1][0]<<endl;
			int ans=0;
			for (int i = 0; i <= b; ++i) {
				ans=max(ans, dp[n][i]);
			}
			return ans;
		}
};
