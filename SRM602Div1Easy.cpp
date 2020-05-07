#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define N 52
#define M 2210
#define inf 1000000000
using namespace std;
class TypoCoderDiv1{
	public:
		int n;
		int dp[N][M];
		int getmax(vector<int>D, int X){
			n = D.size();
            memset(dp, -1, sizeof(dp));
            dp[0][X] = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 2200; ++j) {
                    if (dp[i][j]>=0) {
                    	dp[i+1][max(0, j-D[i])] = max(dp[i+1][max(0,j-D[i])], dp[i][j]);
                        if (j+D[i]<2200) {
                        	dp[i+1][j+D[i]] = max(dp[i+1][j+D[i]], dp[i][j]);
                        } else {
                            if (i==n-1) {
                            	dp[i+1][2200] = max(dp[i+1][2200], dp[i][j]+1);
                            } else {
                                if (j+D[i]-D[i+1]<2200) {
                                	dp[i+2][max(0, j+D[i]-D[i+1])] = max(dp[i+2][max(0, j+D[i]-D[i+1])], dp[i][j]+2);
                                }
                            }
                        }
                    }
                }
            }
            int ans=0;
            for (int i = 0; i <= 2200; ++i) {
            	ans = max(ans, dp[n][i]);
            }
		/*	for(int i = 0;i<=n;++i)
				for(int j = 0;j<=2200;++j)
					f[i][j] = -inf;
			f[0][X] = 0;
			int ans = 0;
			for(int i = 0;i<n;++i)
				for(int j = 0;j<2200;++j)
					if(f[i][j]>=0){
						f[i+1][max(0,j-D[i])] = max(f[i+1][max(0,j-D[i])],f[i][j]);
						ans = max(ans,f[i+1][max(0,j-D[i])]);
						if(j+D[i]>=2200){
							
							if(i==n-1)
								ans = max(ans,f[i][j]+1);
							else{
								
								if(j+D[i]-D[i+1]<2200){
									f[i+2][max(0,j+D[i]-D[i+1])] = max(f[i+2][max(0,j+D[i]-D[i+1])],f[i][j]+2);
									ans = max(ans,f[i+2][max(0,j+D[i]-D[i+1])]);
								}
							}
						}
						else{
							f[i+1][j+D[i]] = max(f[i+1][j+D[i]],f[i][j]);
							ans = max(ans,f[i+1][j+D[i]]);
						}
					} */
					return ans;
		}
};
