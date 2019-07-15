#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
class AlternativePiles {
public:
    int dp[5002][52][52];
    int n;
    int count(string C, int m) {
    	n = C.size();
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; ++i) {
        	for (int j = 0; j < m; ++j) {
            	for (int k = 0; k <= m; ++k) {
                	if (C[i] == 'W' || C[i] == 'R') {
                    	if (k < m) {
                        	dp[i+1][j][k+1] += dp[i][j][k];
                            if (dp[i+1][j][k+1] >= mod) dp[i+1][j][k+1] -= mod;
                        }
                    }
                    if (C[i] == 'W' || C[i] == 'G') {
                    	if (k > 0) {
                        	dp[i+1][(j+1)%m][k-1] += dp[i][j][k];
                            if (dp[i+1][(j+1)%m][k-1] >= mod) dp[i+1][(j+1)%m][k-1] -= mod;
                        }
                    }
                    if (C[i] == 'W' || C[i] == 'B') {
                    	dp[i+1][j][k] += dp[i][j][k];
                        if (dp[i+1][j][k] >= mod) dp[i+1][j][k] -= mod;
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};
