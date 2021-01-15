#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define N 52
using namespace std;
typedef long long ll;
class MarbleDrawGame {
  public:
    ll comb[N][N];
    double winningChance(vector<int> ms) {
      memset(comb, 0LL, sizeof(comb));
      int n = ms.size();
      for (int i = 0; i <= 50; ++i) {
        comb[i][0] = 1LL;
        for (int j = 1; j <= min(i,9); ++j) {
          comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
      }
      ll dp[2][n+2][10];
      memset(dp, 0LL, sizeof(dp));
      dp[0][0][0] = 1LL;
      dp[1][0][0] = 1LL;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 9; ++j) {
          for (int k = 0; k <= min(4, ms[i]); ++k) {
          //  int det=9-j;
            if (j+k <= 9) dp[1][i+1][j+k] += dp[1][i][j]*comb[ms[i]][k];
          }
          for (int k = 0; k <= ms[i]; ++k) {
          //  int det=9-j;
            if (j+k <= 9) dp[0][i+1][j+k] += dp[0][i][j]*comb[ms[i]][k];
          }
        }
      }
      double pr = (double)dp[1][n][9] / (double)dp[0][n][9];
      return 1.0-pr;
    }
};
